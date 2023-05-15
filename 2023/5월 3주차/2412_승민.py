import sys
from collections import deque

input = sys.stdin.readline

n, t = map(int, input().split())
home = []
c = 0
r = t
answer = int(1e9)

for _ in range(n):
    x, y = map(int, input().split())
    c = max(c, x)
    home.append([x, y])

graph = [[0]*(c+1) for _ in range(r+1)]
visited = [[False]*(c+1) for _ in range(r+1)]

for elem in home:
    h_x, h_y = elem[0], elem[1]
    graph[h_y][h_x] = -1

queue = deque([])
queue.append([0, 0])
visited[0][0] = True
canReach = False

while queue:
    now_y, now_x = queue.popleft()

    for i in range(-2, 3):
        for j in range(-2, 3):
            ny = now_y + i
            nx = now_x + j
            if 0<=nx<=c and 0<=ny<=r and not visited[ny][nx]:
                if graph[ny][nx] == -1:
                    graph[ny][nx] = graph[now_y][now_x] + 1
                    if ny == t:
                        canReach = True
                        answer = min(answer, graph[ny][nx])
                    visited[ny][nx] = True
                    queue.append([ny, nx])

if not canReach:
    print(-1)
else:
    print(answer)
