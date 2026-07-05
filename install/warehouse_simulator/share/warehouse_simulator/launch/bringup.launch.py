from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="tf2_ros",
            executable="static_transform_publisher",
            name="static_tf",
            arguments=["0", "0", "0", "0", "0", "0", "world", "map"],
            output="screen",
        ),
        Node(
            package="warehouse_simulator",
            executable="warehouse_map",
            name="warehouse_map",
            output="screen",
        ),
        Node(
            package="warehouse_simulator",
            executable="robot_agent",
            name="robot_1",
            output="screen",
            parameters=[{"robot_id": "robot_1", "start_x": 6.0, "start_y": 4.0}]
        ),
        Node(
            package="warehouse_simulator",
            executable="robot_agent",
            name="robot_2",
            output="screen",
            parameters=[{"robot_id": "robot_2", "start_x": 6.0, "start_y": 8.0}]
        ),
        Node(
            package="warehouse_simulator",
            executable="robot_agent",
            name="robot_3",
            output="screen",
            parameters=[{"robot_id": "robot_3", "start_x": 6.0, "start_y": 12.0}]
        ),
        Node(
            package="warehouse_simulator",
            executable="fleet_manager",
            name="fleet_manager",
            output="screen",
        ),
    ])
