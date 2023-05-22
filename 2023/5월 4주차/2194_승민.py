import sys
from collections import deque

input = sys.stdin.readline

# a가 유닛의 행 크기, b가 유닛의 열 크기
n, m, a, b, k = map(int, input().split())

graph = [[0] * (m+1) for _ in range(n+1)]
visited = [[False] * (m+1) for _ in range(n+1)]
dx = [-1, 1, 0, 0]
dy = [0, 0 , -1, 1]

# 장애물 표시
for _ in range(k):
    r, c = map(int, input().split())
    graph[r][c] = -1

# 시작과 끝의 왼쪽 맨 위 점
# 왼쪽 맨 위 점을 기준으로 움직이면 어떨까?
start_y, start_x = map(int, input().split())
end_y, end_x = map(int, input().split())

queue = deque([])
queue.append([start_y, start_x])
visited[start_y][start_x] = True

while queue:
    now_y, now_x = queue.popleft()
    for i in range(4):
        canGo = True
        ny = now_y + dy[i]
        nx = now_x + dx[i]
        if 0<ny and 0<nx and ny+a-1<=n and nx+b-1<=m and not visited[ny][nx]:
            # 모든 블록 순회하면서 장애물 체크
            for j in range(a):
                for k in range(b):
                    if graph[ny+j][nx+k] == -1:
                        canGo = False
                        break
            
            if not canGo:
                continue

            if ny==end_y and nx==end_x:
                print(graph[now_y][now_x]+1)
                exit(0)

            visited[ny][nx] = True
            queue.append([ny, nx])
            # 왜 이 코드는 틀린거고
            for j in range(a):
                for k in range(b):
                    graph[ny+j][nx+k] = graph[now_y][now_x]+1
            # 왜 이 코드는 맞는거지..?
            graph[ny][nx] = graph[now_y][now_x]+1
            
print(-1)