import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose2D
from std_msgs.msg import String
from warehouse_interfaces.srv import AssignTask
from rclpy.qos import QoSProfile, ReliabilityPolicy
import math

ROBOT_IDS = ['robot_1', 'robot_2', 'robot_3']

class FleetManager(Node):
    def __init__(self):
        super().__init__('fleet_manager')
        self.robot_poses   = {r: (0.0, 0.0) for r in ROBOT_IDS}
        self.robot_states  = {r: 'idle' for r in ROBOT_IDS}
        self.robot_targets = {r: None for r in ROBOT_IDS}

        reliable_qos = QoSProfile(
            depth=10,
            reliability=ReliabilityPolicy.RELIABLE
        )

        for robot_id in ROBOT_IDS:
            self.create_subscription(
                Pose2D, f'/{robot_id}/pose',
                lambda msg, r=robot_id: self.pose_callback(msg, r), 10)
            self.create_subscription(
                String, f'/{robot_id}/status',
                lambda msg, r=robot_id: self.status_callback(msg, r), 10)

        self.cmd_pubs = {
            r: self.create_publisher(Pose2D, f'/{r}/cmd', reliable_qos)
            for r in ROBOT_IDS
        }
        self.reserved_pub = self.create_publisher(
            String, '/fleet/reserved_cells', 10)
        self.srv = self.create_service(
            AssignTask, '/fleet/assign_task', self.assign_task_callback)
        self.create_timer(0.2, self.publish_reserved_cells)
        self.get_logger().info('Fleet manager ready — waiting for tasks')

    def pose_callback(self, msg, robot_id):
        self.robot_poses[robot_id] = (msg.x, msg.y)

    def status_callback(self, msg, robot_id):
        new_state = msg.data
        old_state = self.robot_states[robot_id]
        if new_state != old_state:
            self.robot_states[robot_id] = new_state
            if new_state == 'done':
                self.get_logger().info(f'{robot_id} completed its task')
                self.robot_targets[robot_id] = None

    def publish_reserved_cells(self):
        cells = []
        for robot_id in ROBOT_IDS:
            x, y = self.robot_poses[robot_id]
            cells.append(f'{int(round(x))},{int(round(y))}')
            if self.robot_targets[robot_id]:
                tx, ty = self.robot_targets[robot_id]
                cells.append(f'{int(round(tx))},{int(round(ty))}')
        msg = String()
        msg.data = ';'.join(cells)
        self.reserved_pub.publish(msg)

    def assign_task_callback(self, request, response):
        target_x = request.target_x
        target_y = request.target_y
        task_id  = request.task_id
        self.get_logger().info(
            f'Task {task_id} received → target ({target_x}, {target_y})')

        best_robot = None
        best_dist  = float('inf')
        for robot_id in ROBOT_IDS:
            if self.robot_states[robot_id] in ('idle', 'done'):
                rx, ry = self.robot_poses[robot_id]
                dist = math.sqrt((target_x-rx)**2 + (target_y-ry)**2)
                if dist < best_dist:
                    best_dist  = dist
                    best_robot = robot_id

        if best_robot is None:
            response.success        = False
            response.assigned_robot = ''
            response.message        = 'No free robots available'
            self.get_logger().warn('All robots busy!')
            return response

        cmd = Pose2D()
        cmd.x = float(target_x)
        cmd.y = float(target_y)
        self.cmd_pubs[best_robot].publish(cmd)
        self.robot_targets[best_robot] = (target_x, target_y)
        self.robot_states[best_robot]  = 'moving'

        response.success        = True
        response.assigned_robot = best_robot
        response.message        = (
            f'{best_robot} assigned to task {task_id} '
            f'(dist: {best_dist:.1f})')
        self.get_logger().info(f'Assigned {best_robot} to task {task_id}')
        return response

def main(args=None):
    rclpy.init(args=args)
    node = FleetManager()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
