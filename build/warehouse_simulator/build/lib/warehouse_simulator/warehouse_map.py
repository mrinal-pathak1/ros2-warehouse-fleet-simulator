import rclpy
from rclpy.node import Node
from nav_msgs.msg import OccupancyGrid
from std_msgs.msg import Header
import numpy as np

# Grid config — 20x20 cells, each cell = 1 metre
GRID_W = 20
GRID_H = 20
RESOLUTION = 1.0  # metres per cell

def build_warehouse_grid():
    """
    0 = free space (aisles)
    100 = occupied (shelves / walls)
    """
    grid = np.zeros((GRID_H, GRID_W), dtype=np.int8)

    # Outer walls
    grid[0, :]  = 100
    grid[-1, :] = 100
    grid[:, 0]  = 100
    grid[:, -1] = 100

    # Shelf rows — two columns of shelves with an aisle down the middle
    shelf_rows = [3, 4, 7, 8, 11, 12, 15, 16]
    shelf_cols_left  = [2, 3, 4]
    shelf_cols_right = [15, 16, 17]

    for r in shelf_rows:
        for c in shelf_cols_left + shelf_cols_right:
            grid[r][c] = 100

    return grid.flatten().tolist()


class WarehouseMapPublisher(Node):
    def __init__(self):
        super().__init__('warehouse_map')
        self.publisher_ = self.create_publisher(OccupancyGrid, '/map', 10)
        self.timer = self.create_timer(2.0, self.publish_map)  # publish every 2s
        self.get_logger().info('Warehouse map node started')

    def publish_map(self):
        msg = OccupancyGrid()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'map'

        msg.info.resolution = RESOLUTION
        msg.info.width  = GRID_W
        msg.info.height = GRID_H
        msg.info.origin.position.x = 0.0
        msg.info.origin.position.y = 0.0
        msg.info.origin.position.z = 0.0
        msg.info.origin.orientation.w = 1.0

        msg.data = build_warehouse_grid()
        self.publisher_.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = WarehouseMapPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()