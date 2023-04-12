import sys

input = sys.stdin.readline

r, c, k = map(int, input().split())

graph = [list(input().rstrip()) for _ in range(r)]
visited = [[False] * c for _ in range(r)]
answer = 0

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def dfs(i, j, cnt):
    global k, answer
    if cnt == k:
        if i == 0 and j == c-1:
            answer += 1
        return
    
    visited[i][j] = True

    for l in range(4):
        ny = i + dy[l]
        nx = j + dx[l]
        if 0 <= ny < r and 0 <= nx < c and graph[ny][nx] != 'T' and visited[ny][nx] == False:
            dfs(ny, nx, cnt+1)
            visited[ny][nx] = False

dfs(r-1, 0, 1)

print(answer)