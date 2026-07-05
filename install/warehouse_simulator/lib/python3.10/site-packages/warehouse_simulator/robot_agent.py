import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose2D, Point
from std_msgs.msg import String
from visualization_msgs.msg import Marker, MarkerArray
from warehouse_simulator.pathfinder import astar
import math

class RobotAgent(Node):
    def __init__(self):
        super().__init__("robot_agent")
        self.declare_parameter("robot_id", "robot_1")
        self.declare_parameter("start_x", 7.0)
        self.declare_parameter("start_y", 10.0)
        self.robot_id = self.get_parameter("robot_id").value
        self.x = self.get_parameter("start_x").value
        self.y = self.get_parameter("start_y").value
        self.start_x = self.x
        self.start_y = self.y

        self.state       = "idle"
        self.waypoints   = []
        self.speed       = 0.15
        self.text_timer  = 0
        self.carrying    = False
        self.dropoff     = None
        self.pickup_pos  = None

        self.pose_pub    = self.create_publisher(Pose2D,      f"/{self.robot_id}/pose",   10)
        self.status_pub  = self.create_publisher(String,      f"/{self.robot_id}/status", 10)
        self.marker_pub  = self.create_publisher(MarkerArray, "/visualization_marker_array", 10)
        self.pickup_pub  = self.create_publisher(String,      "/warehouse/pickup",  10)
        self.dropoff_pub = self.create_publisher(String,      "/warehouse/dropoff", 10)

        self.cmd_sub = self.create_subscription(
            String, f"/{self.robot_id}/cmd", self.cmd_callback, 10)
        self.reserved_sub = self.create_subscription(
            String, "/fleet/reserved_cells", self.reserved_callback, 10)

        self.reserved_cells = set()
        self.timer = self.create_timer(0.05, self.update)  # 20Hz for smooth movement
        self.get_logger().info(f"{self.robot_id} ready at ({self.x}, {self.y})")

    def reserved_callback(self, msg):
        cells = set()
        if msg.data:
            for pair in msg.data.split(";"):
                if "," in pair:
                    try:
                        x, y = pair.split(",")
                        cells.add((int(x), int(y)))
                    except ValueError:
                        pass
        self.reserved_cells = cells

    def cmd_callback(self, msg):
        if self.state in ("idle", "done", "returning"):
            try:
                pickup_part, drop_part = msg.data.split("|")
                px, py = [float(v) for v in pickup_part.split(",")]
                dx, dy = [float(v) for v in drop_part.split(",")]
            except Exception:
                self.get_logger().error(f"Bad cmd: {msg.data}")
                return
            self.dropoff    = (dx, dy)
            self.pickup_pos = (px, py)
            self.carrying   = False
            path = astar((self.x, self.y), (px, py), self.reserved_cells)
            if path:
                self.waypoints = path[1:]
                self.state     = "going_to_pickup"
                self.get_logger().info(f"{self.robot_id} going to pickup ({px},{py})")
            else:
                self.get_logger().warn(f"{self.robot_id} no path to ({px},{py})")

    def update(self):
        if self.state in ("going_to_pickup", "carrying", "returning") and self.waypoints:
            wp = self.waypoints[0]
            dx = wp[0] - self.x
            dy = wp[1] - self.y
            dist = math.sqrt(dx**2 + dy**2)

            if dist < 0.05:
                self.x = float(wp[0])
                self.y = float(wp[1])
                self.waypoints.pop(0)

                if not self.waypoints:
                    if self.state == "going_to_pickup":
                        px = int(round(self.pickup_pos[0]))
                        py = int(round(self.pickup_pos[1]))
                        notify = String()
                        notify.data = f"{px},{py}"
                        self.pickup_pub.publish(notify)
                        self.carrying = True
                        self.state    = "carrying"
                        self.get_logger().info(f"{self.robot_id} picked up box!")
                        path = astar((self.x, self.y), self.dropoff, self.reserved_cells)
                        if path:
                            self.waypoints = path[1:]
                        else:
                            self.get_logger().error(f"{self.robot_id} no path to dropoff!")
                            self.state = "done"

                    elif self.state == "carrying":
                        dx2 = int(round(self.dropoff[0]))
                        dy2 = int(round(self.dropoff[1]))
                        notify = String()
                        notify.data = f"{dx2},{dy2}"
                        self.dropoff_pub.publish(notify)
                        self.carrying   = False
                        self.text_timer = 30
                        self.get_logger().info(f"{self.robot_id} delivered! returning to base...")
                        # Return to start
                        path = astar((self.x, self.y),
                                     (self.start_x, self.start_y),
                                     self.reserved_cells)
                        if path:
                            self.waypoints = path[1:]
                            self.state = "returning"
                        else:
                            self.state = "done"

                    elif self.state == "returning":
                        self.state = "done"
                        self.get_logger().info(f"{self.robot_id} back at base, idle.")
            else:
                step = min(self.speed, dist)
                self.x += (dx / dist) * step
                self.y += (dy / dist) * step

        if self.text_timer > 0:
            self.text_timer -= 1

        self.publish_pose()
        self.publish_status()
        self.publish_markers()

    def publish_pose(self):
        msg = Pose2D()
        msg.x = self.x
        msg.y = self.y
        self.pose_pub.publish(msg)

    def publish_status(self):
        msg = String()
        msg.data = "moving" if self.state in ("going_to_pickup", "carrying", "returning") else self.state
        self.status_pub.publish(msg)

    def publish_markers(self):
        array = MarkerArray()
        stamp = self.get_clock().now().to_msg()

        # Robot body
        robot = Marker()
        robot.header.frame_id = "map"
        robot.header.stamp    = stamp
        robot.ns   = self.robot_id
        robot.id   = 0
        robot.type = Marker.CYLINDER
        robot.action = Marker.ADD
        robot.pose.position.x = self.x
        robot.pose.position.y = self.y
        robot.pose.position.z = 0.25
        robot.pose.orientation.w = 1.0
        robot.scale.x = 0.6
        robot.scale.y = 0.6
        robot.scale.z = 0.5
        robot.color.r, robot.color.g, robot.color.b = 0.2, 0.6, 1.0
        robot.color.a = 1.0
        array.markers.append(robot)

        # Direction arrow
        arrow = Marker()
        arrow.header.frame_id = "map"
        arrow.header.stamp    = stamp
        arrow.ns   = f"{self.robot_id}_arrow"
        arrow.id   = 1
        arrow.type = Marker.ARROW
        arrow.action = Marker.ADD
        arrow.pose.position.x = self.x
        arrow.pose.position.y = self.y
        arrow.pose.position.z = 0.55
        angle = 0.0
        if self.state in ("going_to_pickup", "carrying", "returning") and self.waypoints:
            # Look ahead 3 waypoints for smoother arrow direction
            lookahead = self.waypoints[min(2, len(self.waypoints)-1)]
            angle = math.atan2(lookahead[1] - self.y, lookahead[0] - self.x)
        arrow.pose.orientation.z = math.sin(angle / 2)
        arrow.pose.orientation.w = math.cos(angle / 2)
        arrow.scale.x = 0.8
        arrow.scale.y = 0.2
        arrow.scale.z = 0.2
        arrow.color.r = 1.0
        arrow.color.g = 1.0
        arrow.color.b = 0.0
        arrow.color.a = 1.0
        array.markers.append(arrow)

        # Carried box
        if self.carrying:
            box = Marker()
            box.header.frame_id = "map"
            box.header.stamp    = stamp
            box.ns   = f"{self.robot_id}_box"
            box.id   = 2
            box.type = Marker.CUBE
            box.action = Marker.ADD
            box.pose.position.x = self.x
            box.pose.position.y = self.y
            box.pose.position.z = 1.3
            box.pose.orientation.w = 1.0
            box.scale.x = 0.9
            box.scale.y = 0.9
            box.scale.z = 1.5
            box.color.r = 0.55
            box.color.g = 0.35
            box.color.b = 0.1
            box.color.a = 1.0
            array.markers.append(box)
        else:
            del_box = Marker()
            del_box.header.frame_id = "map"
            del_box.header.stamp    = stamp
            del_box.ns   = f"{self.robot_id}_box"
            del_box.id   = 2
            del_box.action = Marker.DELETE
            array.markers.append(del_box)

        # DELIVERED text — floats above delivery spot, no balloon
        if self.text_timer > 0:
            text = Marker()
            text.header.frame_id = "map"
            text.header.stamp    = stamp
            text.ns   = f"{self.robot_id}_text"
            text.id   = 5
            text.type = Marker.TEXT_VIEW_FACING
            text.action = Marker.ADD
            text.pose.position.x = self.x
            text.pose.position.y = self.y
            text.pose.position.z = 3.0
            text.pose.orientation.w = 1.0
            text.scale.z = 0.7
            text.color.r = 0.0
            text.color.g = 1.0
            text.color.b = 0.3
            text.color.a = min(1.0, float(self.text_timer) / 15.0)
            text.text = "DELIVERED ✓"
            array.markers.append(text)
        else:
            del_text = Marker()
            del_text.header.frame_id = "map"
            del_text.header.stamp    = stamp
            del_text.ns   = f"{self.robot_id}_text"
            del_text.id   = 5
            del_text.action = Marker.DELETE
            array.markers.append(del_text)

        # Path trail
        if self.waypoints:
            trail = Marker()
            trail.header.frame_id = "map"
            trail.header.stamp    = stamp
            trail.ns   = f"{self.robot_id}_path"
            trail.id   = 4
            trail.type = Marker.LINE_STRIP
            trail.action = Marker.ADD
            trail.scale.x = 0.12
            colors = {
                "robot_1": (1.0, 0.3, 0.3),
                "robot_2": (0.3, 0.6, 1.0),
                "robot_3": (0.3, 1.0, 0.5),
            }
            r, g, b = colors.get(self.robot_id, (1.0, 1.0, 1.0))
            trail.color.r = r
            trail.color.g = g
            trail.color.b = b
            trail.color.a = 0.8
            p = Point()
            p.x = self.x
            p.y = self.y
            p.z = 0.3
            trail.points.append(p)
            for wp in self.waypoints:
                p = Point()
                p.x = float(wp[0])
                p.y = float(wp[1])
                p.z = 0.3
                trail.points.append(p)
            array.markers.append(trail)

        self.marker_pub.publish(array)

def main(args=None):
    rclpy.init(args=args)
    node = RobotAgent()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
