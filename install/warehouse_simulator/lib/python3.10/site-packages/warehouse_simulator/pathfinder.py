import heapq

# Must match warehouse_map.py
GRID_W = 20
GRID_H = 20

# Obstacle map — built once from the same logic as warehouse_map.py
def build_obstacle_set():
    obstacles = set()

    # Outer walls
    for x in range(GRID_W):
        obstacles.add((x, 0))
        obstacles.add((x, GRID_H - 1))
    for y in range(GRID_H):
        obstacles.add((0, y))
        obstacles.add((GRID_W - 1, y))

    # Shelf rows — must match warehouse_map.py exactly
    shelf_rows = [3, 4, 7, 8, 11, 12, 15, 16]
    shelf_cols_left  = [2, 3, 4]
    shelf_cols_right = [15, 16, 17]

    for r in shelf_rows:
        for c in shelf_cols_left + shelf_cols_right:
            obstacles.add((c, r))

    return obstacles

OBSTACLES = build_obstacle_set()


def heuristic(a, b):
    """Manhattan distance."""
    return abs(a[0] - b[0]) + abs(a[1] - b[1])


def astar(start, goal, reserved_cells=None):
    """
    A* pathfinding on the warehouse grid.
    start, goal: (x, y) tuples of integers
    reserved_cells: set of (x, y) cells blocked by other robots
    Returns list of (x, y) waypoints from start to goal, or [] if no path.
    """
    if reserved_cells is None:
        reserved_cells = set()

    # Snap to integer grid cells
    start = (int(round(start[0])), int(round(start[1])))
    goal  = (int(round(goal[0])),  int(round(goal[1])))

    # Validate start and goal
    if start in OBSTACLES or goal in OBSTACLES:
        return []

    open_heap = []
    heapq.heappush(open_heap, (0, start))

    came_from = {}
    g_score = {start: 0}

    while open_heap:
        _, current = heapq.heappop(open_heap)

        if current == goal:
            # Reconstruct path
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            path.reverse()
            return path

        # 4-directional movement (no diagonals)
        for dx, dy in [(1,0),(-1,0),(0,1),(0,-1)]:
            neighbor = (current[0] + dx, current[1] + dy)

            # Skip obstacles and reserved cells (but always allow goal)
            if neighbor in OBSTACLES:
                continue
            if neighbor in reserved_cells and neighbor != goal:
                continue
            if not (0 <= neighbor[0] < GRID_W and
                    0 <= neighbor[1] < GRID_H):
                continue

            tentative_g = g_score[current] + 1

            if tentative_g < g_score.get(neighbor, float('inf')):
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g
                f = tentative_g + heuristic(neighbor, goal)
                heapq.heappush(open_heap, (f, neighbor))

    return []  # No path found