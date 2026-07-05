# Multi-Robot Warehouse Fleet Simulator

A ROS2-based warehouse automation simulator featuring 3 autonomous robots coordinated by a central fleet manager. Robots navigate a 20×20 grid warehouse, pick up boxes from shelf locations, deliver them to vacant slots, and return to base — collision-free by design.

**Skills:** ROS2 · Python · RViz2

## System Architecture
<img width="840" height="458" alt="image" src="https://github.com/user-attachments/assets/8e2b6c27-1106-4ed7-bfff-3cad317de5df" />

## Key Technical Work

- **A\* pathfinding** on a 20×20 occupancy grid — robots navigate around shelf obstacles via waypoint following
- **Fleet manager service** assigns tasks to the nearest available robot using Euclidean distance; deque-based task queue handles 10+ concurrent tasks without dropping
- **Two-phase pickup/delivery state machine**: idle → pickup → carry → return
- Debugged QoS mismatches, race conditions, and state machine edge cases across a distributed 5-node ROS2 architecture

## Demo



https://github.com/user-attachments/assets/2d404b2d-f84c-44b8-8d2a-ef7f4f6eeb81



---
Personal project, May–Jun 2026.
