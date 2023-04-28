import sys
import copy
from collections import deque

input = sys.stdin.readline

n, m, t = map(int, input().split())

graph = [list(map(int, input().split())) for _ in range(n)]

g_x = g_y = 0
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]
INF = int(1e5)

for i in range(n):
    for j in range(m):
        if graph[i][j] == 2:
            g_y = i
            g_x = j
            graph[i][j] = 0

visited = [[False] * m for _ in range(n)]
g_visited = copy.deepcopy(visited)

def bfs(g, v, st_x, st_y):
    queue = deque([])
    queue.append([st_y, st_x])

    while queue:
        y, x = queue.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if 0<=ny<n and 0<=nx<m and v[ny][nx] == False and g[ny][nx] == 0:
                v[ny][nx] = True
                queue.append([ny, nx])
                g[ny][nx] = g[y][x] + 1

visited[0][0] = True
bfs(graph, visited, 0, 0)

# 검 없이 도달 불가능
if graph[n-1][m-1] == 0:
    # 검을 찾을 수 없으면
    if graph[g_y][g_x] == 0:
        print('Fail')
    # 검을 찾을 수 있으면
    else:
        total = graph[g_y][g_x] + n-1-g_y + m-1-g_x
        if total <= t:
            print(total)
        else:
            print('Fail')
# 검 없어도 도달 가능
else:
    # 검을 찾을 수 없으면
    if graph[g_y][g_x] == 0:
        if graph[n-1][m-1] <= t:
            print(graph[n-1][m-1])
        else:
            print('Fail')
    # 검을 찾을 수 있으면
    else:
        total = graph[g_y][g_x] + n-1-g_y + m-1-g_x
        ans = min(graph[n-1][m-1], total)
        if ans <= t:
            print(ans)
        else:
            print('Fail')
