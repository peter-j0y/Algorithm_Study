import sys
from collections import deque
input = sys.stdin.readline

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

m, n = map(int, input().split())
graph = []
queue = deque()
maxCount = 1

for i in range(n):
    graph.append(list(map(int, input().split())))
    for j in range(m):
        if graph[i][j] == 1 :
            queue.append([i, j])

def bfs() :
    while(queue) :
        y, x = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<m and 0<=ny<n and graph[ny][nx] == 0:
                graph[ny][nx] = graph[y][x] + 1
                queue.append([ny, nx])

bfs()
result = max(map(max, graph)) - 1

for i in range(n):
    for j in range(m):
        if graph[i][j] == 0 :
            result = -1
            break
    if result == -1:
        break

print(result)
