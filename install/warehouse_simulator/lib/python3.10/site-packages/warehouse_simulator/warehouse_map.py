import rclpy
from rclpy.node import Node
from nav_msgs.msg import OccupancyGrid
from visualization_msgs.msg import Marker, MarkerArray
from std_msgs.msg import String
import numpy as np

GRID_W = 20
GRID_H = 20
RESOLUTION = 1.0
SHELF_ROWS       = [3, 4, 7, 8, 11, 12, 15, 16]
SHELF_COLS_LEFT  = [2, 3, 4]
SHELF_COLS_RIGHT = [15, 16, 17]

# Pickup spots: loose boxes on floor beside left shelves
# Using half-cell centers to match exactly what robot sends
PICKUP_SPOTS  = {(5, 4), (5, 8), (5, 12)}
DROPOFF_SPOTS = {(14, 4), (14, 8), (14, 12)}

def build_warehouse_grid():
    grid = np.zeros((GRID_H, GRID_W), dtype=np.int8)
    grid[0, :]  = 100
    grid[-1, :] = 100
    grid[:, 0]  = 100
    grid[:, -1] = 100
    for r in SHELF_ROWS:
        for c in SHELF_COLS_LEFT + SHELF_COLS_RIGHT:
            grid[r][c] = 100
    return grid.flatten().tolist()

def make_cube(ns, mid, cx, cy, cz, sx, sy, sz, r, g, b, a, stamp):
    m = Marker()
    m.header.frame_id = "map"
    m.header.stamp    = stamp
    m.ns     = ns
    m.id     = mid
    m.type   = Marker.CUBE
    m.action = Marker.ADD
    m.pose.position.x    = float(cx)
    m.pose.position.y    = float(cy)
    m.pose.position.z    = float(cz)
    m.pose.orientation.w = 1.0
    m.scale.x = float(sx)
    m.scale.y = float(sy)
    m.scale.z = float(sz)
    m.color.r = float(r)
    m.color.g = float(g)
    m.color.b = float(b)
    m.color.a = float(a)
    return m

def make_delete(ns, mid, stamp):
    m = Marker()
    m.header.frame_id = "map"
    m.header.stamp    = stamp
    m.ns     = ns
    m.id     = mid
    m.action = Marker.DELETE
    return m

class WarehouseMapPublisher(Node):
    def __init__(self):
        super().__init__("warehouse_map")
        self.map_pub    = self.create_publisher(OccupancyGrid, "/map", 10)
        self.marker_pub = self.create_publisher(MarkerArray, "/warehouse_markers", 10)
        self.create_timer(2.0, self.publish_map)
        self.create_timer(0.2, self.publish_markers)

        self.loose_boxes  = set(PICKUP_SPOTS)   # boxes still on floor
        self.filled_slots = set()               # slots that received a box

        self.create_subscription(String, "/warehouse/pickup",  self.pickup_cb,  10)
        self.create_subscription(String, "/warehouse/dropoff", self.dropoff_cb, 10)
        self.get_logger().info("Warehouse map node started")

    def pickup_cb(self, msg):
        try:
            x, y = [float(v) for v in msg.data.split(",")]
            key = (int(round(x)), int(round(y)))
            self.get_logger().info(f"Pickup event at {key}, loose_boxes={self.loose_boxes}")
            self.loose_boxes.discard(key)
        except Exception as e:
            self.get_logger().error(f"pickup_cb error: {e}")

    def dropoff_cb(self, msg):
        try:
            x, y = [float(v) for v in msg.data.split(",")]
            key = (int(round(x)), int(round(y)))
            self.get_logger().info(f"Dropoff event at {key}")
            self.filled_slots.add(key)
        except Exception as e:
            self.get_logger().error(f"dropoff_cb error: {e}")

    def publish_map(self):
        msg = OccupancyGrid()
        msg.header.stamp    = self.get_clock().now().to_msg()
        msg.header.frame_id = "map"
        msg.info.resolution = RESOLUTION
        msg.info.width      = GRID_W
        msg.info.height     = GRID_H
        msg.info.origin.position.x = 0.0
        msg.info.origin.position.y = 0.0
        msg.info.origin.position.z = 0.0
        msg.info.origin.orientation.w = 1.0
        msg.data = build_warehouse_grid()
        self.map_pub.publish(msg)

    def publish_markers(self):
        array = MarkerArray()
        mid   = 0
        stamp = self.get_clock().now().to_msg()

        # Floor
        array.markers.append(make_cube(
            "warehouse", mid, GRID_W/2, GRID_H/2, -0.05,
            GRID_W, GRID_H, 0.1, 0.85, 0.85, 0.75, 1.0, stamp))
        mid += 1

        # Walls
        for cx, cy, sx, sy in [
            (GRID_W/2,   0.5,          GRID_W, 1.0),
            (GRID_W/2,   GRID_H - 0.5, GRID_W, 1.0),
            (0.5,        GRID_H/2,     1.0,    GRID_H),
            (GRID_W-0.5, GRID_H/2,     1.0,    GRID_H),
        ]:
            array.markers.append(make_cube(
                "warehouse", mid, cx, cy, 1.0,
                sx, sy, 2.0, 0.4, 0.4, 0.4, 1.0, stamp))
            mid += 1

        # Shelf units
        for r in SHELF_ROWS:
            for c in SHELF_COLS_LEFT + SHELF_COLS_RIGHT:
                slot = (c, r)
                if slot in self.filled_slots:
                    # Delivered — green stripe to show it was filled by robot
                    array.markers.append(make_cube(
                        "shelves", mid, c+0.5, r+0.5, 0.75,
                        0.9, 0.9, 1.5, 0.55, 0.35, 0.1, 1.0, stamp))
                    mid += 1
                    array.markers.append(make_cube(
                        "shelf_stripes", mid, c+0.5, r+0.5, 1.3,
                        0.92, 0.15, 0.15, 0.0, 0.9, 0.2, 1.0, stamp))
                    mid += 1
                elif slot in DROPOFF_SPOTS:
                    # Vacant dropoff — hollow dark shelf
                    array.markers.append(make_cube(
                        "shelves", mid, c+0.5, r+0.5, 0.75,
                        0.9, 0.9, 1.5, 0.15, 0.1, 0.03, 0.4, stamp))
                    mid += 1
                    # Green floor ring = vacancy indicator
                    array.markers.append(make_cube(
                        "dropoff_rings", mid, c+0.5, r+0.5, 0.02,
                        0.85, 0.85, 0.05, 0.0, 1.0, 0.3, 0.8, stamp))
                    mid += 1
                else:
                    array.markers.append(make_cube(
                        "shelves", mid, c+0.5, r+0.5, 0.75,
                        0.9, 0.9, 1.5, 0.55, 0.35, 0.1, 1.0, stamp))
                    mid += 1
                    array.markers.append(make_cube(
                        "shelf_stripes", mid, c+0.5, r+0.5, 1.3,
                        0.92, 0.15, 0.15, 1.0, 0.5, 0.0, 1.0, stamp))
                    mid += 1

        # Loose boxes at pickup spots
        for bx, by in PICKUP_SPOTS:
            if (bx, by) in self.loose_boxes:
                # Box still here
                array.markers.append(make_cube(
                    "loose_boxes", mid, bx+0.5, by+0.5, 0.75,
                    0.9, 0.9, 1.5, 0.55, 0.35, 0.1, 1.0, stamp))
                mid += 1
                array.markers.append(make_cube(
                    "loose_stripes", mid, bx+0.5, by+0.5, 1.3,
                    0.92, 0.15, 0.15, 1.0, 0.5, 0.0, 1.0, stamp))
                mid += 1
                # Yellow floor ring = pickup indicator
                array.markers.append(make_cube(
                    "pickup_rings", mid, bx+0.5, by+0.5, 0.02,
                    0.85, 0.85, 0.05, 1.0, 1.0, 0.0, 0.8, stamp))
                mid += 1
            else:
                # Box was picked up — delete markers
                array.markers.append(make_delete("loose_boxes",   mid, stamp)); mid += 1
                array.markers.append(make_delete("loose_stripes", mid, stamp)); mid += 1
                array.markers.append(make_delete("pickup_rings",  mid, stamp)); mid += 1

        # Standalone delivered boxes at dropoff spots
        for dx, dy in DROPOFF_SPOTS:
            if (dx, dy) in self.filled_slots:
                array.markers.append(make_cube(
                    "delivered_boxes", mid, dx+0.5, dy+0.5, 0.75,
                    0.9, 0.9, 1.5, 0.55, 0.35, 0.1, 1.0, stamp))
                mid += 1
                # Green stripe = delivered by robot
                array.markers.append(make_cube(
                    "delivered_stripes", mid, dx+0.5, dy+0.5, 1.3,
                    0.92, 0.15, 0.15, 0.0, 0.9, 0.2, 1.0, stamp))
                mid += 1
            else:
                # Green vacancy ring
                array.markers.append(make_cube(
                    "dropoff_rings", mid, dx+0.5, dy+0.5, 0.02,
                    0.85, 0.85, 0.05, 0.0, 1.0, 0.3, 0.8, stamp))
                mid += 1

        self.marker_pub.publish(array)

def main(args=None):
    rclpy.init(args=args)
    node = WarehouseMapPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
