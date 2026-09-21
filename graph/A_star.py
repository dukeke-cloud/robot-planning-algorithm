import heapq

def manhattan_heuristic(a, b):
    """曼哈顿距离 h = |x1-x2| + |y1-y2|，网格常用启发函数"""
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def a_star(grid, start, goal):
    """
    grid: 二维列表，0=可通行，1=障碍物
    start: (x,y)起点
    goal: (x,y)终点
    return: 路径列表[(x,y)...] or None
    """
    rows = len(grid)
    cols = len(grid[0])

    # 上下左右四个方向，如需对角线可加上 (1,1),(-1,-1)...
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    # 优先队列 (f, x, y)
    open_heap = []
    heapq.heappush(open_heap, (0, start[0], start[1]))

    # g_score：记录每个点从起点过来的最小代价，初始无穷大
    g_score = {(x, y): float("inf") for x in range(rows) for y in range(cols)}
    g_score[start] = 0

    # f_score = g + h
    f_score = {(x, y): float("inf") for x in range(rows) for y in range(cols)}
    f_score[start] = manhattan_heuristic(start, goal)

    # 记录父节点，用于回溯路径
    came_from = dict()

    while open_heap:
        current_f, x, y = heapq.heappop(open_heap)
        current = (x, y)

        # 到达终点，回溯路径
        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            path.reverse()
            return path

        # 如果弹出的f大于记录的最优f，跳过旧的过期节点
        if current_f > f_score[current]:
            continue

        # 遍历四个邻居
        for dx, dy in directions:
            nx = x + dx
            ny = y + dy
            neighbor = (nx, ny)
            # 判断边界 + 是否障碍物
            if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] == 0:
                tentative_g = g_score[current] + 1  # 每走一步代价+1

                if tentative_g < g_score[neighbor]:
                    came_from[neighbor] = current
                    g_score[neighbor] = tentative_g
                    f_score[neighbor] = tentative_g + manhattan_heuristic(neighbor, goal)
                    heapq.heappush(open_heap, (f_score[neighbor], nx, ny))

    # 找不到路径
    return None


if __name__ == "__main__":
    # 0可通行，1障碍物
    grid = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0],
        [1, 1, 0, 1, 0],
        [0, 0, 0, 0, 0],
    ]
    start_point = (0, 0)
    end_point = (4, 4)

    result_path = a_star(grid, start_point, end_point)
    if result_path:
        print("找到路径：")
        print(result_path)
    else:
        print("没有可行路径")
