import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose2D, Point
from std_msgs.msg import String
from visualization_msgs.msg import Marker
from rclpy.qos import QoSProfile, ReliabilityPolicy
from warehouse_simulator.pathfinder import astar
import math

class RobotAgent(Node):
    def __init__(self):
        super().__init__('robot_agent')
        self.declare_parameter('robot_id', 'robot_1')
        self.declare_parameter('start_x', 2.0)
        self.declare_parameter('start_y', 2.0)
        self.robot_id = self.get_parameter('robot_id').value
        self.x = self.get_parameter('start_x').value
        self.y = self.get_parameter('start_y').value
        self.state = 'idle'
        self.waypoints = []
        self.current_waypoint = None
        self.speed = 0.1

        reliable_qos = QoSProfile(
            depth=10,
            reliability=ReliabilityPolicy.RELIABLE
        )

        self.pose_pub = self.create_publisher(Pose2D, f'/{self.robot_id}/pose', 10)
        self.status_pub = self.create_publisher(String, f'/{self.robot_id}/status', 10)
        self.marker_pub = self.create_publisher(Marker, '/visualization_marker', 10)

        self.cmd_sub = self.create_subscription(
            Pose2D, f'/{self.robot_id}/cmd', self.cmd_callback, reliable_qos)
        self.reserved_sub = self.create_subscription(
            String, '/fleet/reserved_cells', self.reserved_callback, 10)

        self.reserved_cells = set()
        self.timer = self.create_timer(0.1, self.update)
        self.get_logger().info(f'{self.robot_id} ready at ({self.x}, {self.y})')

    def reserved_callback(self, msg):
        cells = set()
        if msg.data:
            for pair in msg.data.split(';'):
                if ',' in pair:
                    try:
                        x, y = pair.split(',')
                        cells.add((int(x), int(y)))
                    except ValueError:
                        pass
        self.reserved_cells = cells

    def cmd_callback(self, msg):
        if self.state in ('idle', 'done'):
            target = (msg.x, msg.y)
            start = (self.x, self.y)
            path = astar(start, target, self.reserved_cells)
            if path:
                self.waypoints = path[1:]
                self.state = 'moving'
                self.get_logger().info(
                    f'{self.robot_id} path found: {len(self.waypoints)} waypoints')
            else:
                self.get_logger().warn(
                    f'{self.robot_id} no path found to {target}')

    def update(self):
        if self.state == 'moving' and self.waypoints:
            wp = self.waypoints[0]
            dx = wp[0] - self.x
            dy = wp[1] - self.y
            dist = math.sqrt(dx**2 + dy**2)

            if dist < 0.15:
                self.x = float(wp[0])
                self.y = float(wp[1])
                self.waypoints.pop(0)
                if not self.waypoints:
                    self.state = 'done'
                    self.get_logger().info(f'{self.robot_id} arrived!')
            else:
                step = min(self.speed, dist)
                self.x += (dx / dist) * step
                self.y += (dy / dist) * step

        self.publish_pose()
        self.publish_status()
        self.publish_marker()
        self.publish_path_marker()

    def publish_pose(self):
        msg = Pose2D()
        msg.x = self.x
        msg.y = self.y
        self.pose_pub.publish(msg)

    def publish_status(self):
        msg = String()
        msg.data = self.state
        self.status_pub.publish(msg)

    def publish_marker(self):
        msg = Marker()
        msg.header.frame_id = 'map'
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.ns = self.robot_id
        msg.id = 0
        msg.type = Marker.ARROW
        msg.action = Marker.ADD
        msg.pose.position.x = self.x
        msg.pose.position.y = self.y
        msg.pose.position.z = 0.1

        if self.state == 'moving' and self.waypoints:
            wp = self.waypoints[0]
            angle = math.atan2(wp[1] - self.y, wp[0] - self.x)
        else:
            angle = 0.0

        msg.pose.orientation.z = math.sin(angle / 2)
        msg.pose.orientation.w = math.cos(angle / 2)
        msg.scale.x = 1.5
        msg.scale.y = 0.5
        msg.scale.z = 0.5

        if self.state == 'moving':
            msg.color.r = 1.0
            msg.color.g = 0.5
            msg.color.b = 0.0
        else:
            msg.color.r = 0.0
            msg.color.g = 0.9
            msg.color.b = 0.2
        msg.color.a = 1.0
        self.marker_pub.publish(msg)

    def publish_path_marker(self):
        if not self.waypoints:
            return
        msg = Marker()
        msg.header.frame_id = 'map'
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.ns = f'{self.robot_id}_path'
        msg.id = 1
        msg.type = Marker.LINE_STRIP
        msg.action = Marker.ADD
        msg.scale.x = 0.15

        colors = {
            'robot_1': (1.0, 0.3, 0.3),
            'robot_2': (0.3, 0.6, 1.0),
            'robot_3': (0.3, 1.0, 0.5),
        }
        r, g, b = colors.get(self.robot_id, (1.0, 1.0, 1.0))
        msg.color.r = r
        msg.color.g = g
        msg.color.b = b
        msg.color.a = 0.8

        p = Point()
        p.x = self.x
        p.y = self.y
        p.z = 0.1
        msg.points.append(p)

        for wp in self.waypoints:
            p = Point()
            p.x = float(wp[0])
            p.y = float(wp[1])
            p.z = 0.1
            msg.points.append(p)

        self.marker_pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = RobotAgent()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
