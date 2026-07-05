import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose2D
from std_msgs.msg import String
from warehouse_interfaces.srv import AssignTask
import math
from collections import deque

ROBOT_IDS = ["robot_1", "robot_2", "robot_3"]

class FleetManager(Node):
    def __init__(self):
        super().__init__("fleet_manager")
        self.robot_poses   = {r: (0.0, 0.0) for r in ROBOT_IDS}
        self.robot_states  = {r: "idle" for r in ROBOT_IDS}
        self.robot_targets = {r: None for r in ROBOT_IDS}
        self.task_queue    = deque()

        for robot_id in ROBOT_IDS:
            self.create_subscription(Pose2D, f"/{robot_id}/pose",
                lambda msg, r=robot_id: self.pose_callback(msg, r), 10)
            self.create_subscription(String, f"/{robot_id}/status",
                lambda msg, r=robot_id: self.status_callback(msg, r), 10)

        self.cmd_pubs = {
            r: self.create_publisher(String, f"/{r}/cmd", 10)
            for r in ROBOT_IDS
        }
        self.reserved_pub = self.create_publisher(String, "/fleet/reserved_cells", 10)
        self.srv = self.create_service(AssignTask, "/fleet/assign_task", self.assign_task_callback)
        self.create_timer(0.2, self.publish_reserved_cells)
        self.create_timer(0.5, self.process_queue)
        self.get_logger().info("Fleet manager ready — waiting for tasks")

    def pose_callback(self, msg, robot_id):
        self.robot_poses[robot_id] = (msg.x, msg.y)

    def status_callback(self, msg, robot_id):
        new_state = msg.data
        old_state = self.robot_states[robot_id]
        if new_state != old_state:
            self.robot_states[robot_id] = new_state
            if new_state == "done":
                self.get_logger().info(f"{robot_id} completed its task")
                self.robot_targets[robot_id] = None

    def publish_reserved_cells(self):
        cells = []
        for robot_id in ROBOT_IDS:
            x, y = self.robot_poses[robot_id]
            cells.append(f"{int(round(x))},{int(round(y))}")
            if self.robot_targets[robot_id]:
                tx, ty = self.robot_targets[robot_id]
                cells.append(f"{int(round(tx))},{int(round(ty))}")
        msg = String()
        msg.data = ";".join(cells)
        self.reserved_pub.publish(msg)

    def try_assign(self, pickup_x, pickup_y, target_x, target_y, task_id):
        best_robot = None
        best_dist  = float("inf")
        for robot_id in ROBOT_IDS:
            if self.robot_states[robot_id] in ("idle", "done"):
                rx, ry = self.robot_poses[robot_id]
                dist = math.sqrt((pickup_x-rx)**2 + (pickup_y-ry)**2)
                if dist < best_dist:
                    best_dist  = dist
                    best_robot = robot_id

        if best_robot is None:
            return False

        # Send pickup_x,pickup_y|target_x,target_y as a string command
        cmd = String()
        cmd.data = f"{pickup_x},{pickup_y}|{target_x},{target_y}"
        self.cmd_pubs[best_robot].publish(cmd)
        self.robot_targets[best_robot] = (target_x, target_y)
        self.robot_states[best_robot]  = "moving"
        self.get_logger().info(
            f"Assigned {best_robot} to task {task_id}: pickup({pickup_x},{pickup_y}) -> drop({target_x},{target_y})")
        return True

    def process_queue(self):
        while self.task_queue:
            pickup_x, pickup_y, target_x, target_y, task_id = self.task_queue[0]
            if self.try_assign(pickup_x, pickup_y, target_x, target_y, task_id):
                self.task_queue.popleft()
            else:
                break

    def assign_task_callback(self, request, response):
        pickup_x = request.pickup_x
        pickup_y = request.pickup_y
        target_x = request.target_x
        target_y = request.target_y
        task_id  = request.task_id
        self.get_logger().info(f"Task {task_id}: pickup({pickup_x},{pickup_y}) -> drop({target_x},{target_y})")

        if self.try_assign(pickup_x, pickup_y, target_x, target_y, task_id):
            response.success        = True
            response.assigned_robot = "assigned"
            response.message        = f"Task {task_id} assigned immediately"
        else:
            self.task_queue.append((pickup_x, pickup_y, target_x, target_y, task_id))
            response.success        = True
            response.assigned_robot = "queued"
            response.message        = f"Task {task_id} queued (position {len(self.task_queue)})"
        return response

def main(args=None):
    rclpy.init(args=args)
    node = FleetManager()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
