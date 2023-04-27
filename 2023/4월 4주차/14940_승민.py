import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())

graph = [list(map(int, input().split())) for _ in range(n)]

st_y = st_x = 0
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

INF = int(1e5)
for i in range(n):
    for j in range(m):
        if graph[i][j] == 2:
            st_y = i
            st_x = j
        elif graph[i][j] == 1:
            graph[i][j] = INF

graph[st_y][st_x] = 0

queue = deque([])
queue.append([st_y, st_x])
visited = [[False]*m for _ in range(n)]
visited[st_y][st_x] = True

while queue:
    y, x = queue.popleft()
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0<=ny<n and 0<=nx<m and visited[ny][nx] == False and graph[ny][nx] != 0:
            visited[ny][nx] = True
            graph[ny][nx] = graph[y][x] + 1
            queue.append([ny, nx])

for i in range(n):
    for j in range(m):
        if graph[i][j] == INF:
            graph[i][j] = -1

for i in range(n):
    for j in range(m):
        print(graph[i][j], end=' ')
    print()
