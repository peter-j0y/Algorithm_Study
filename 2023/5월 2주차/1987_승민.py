import sys

input = sys.stdin.readline

r, c = map(int, input().split())

graph = [list(input().rstrip()) for _ in range(r)]
visited = [False] * 26
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
answer = 0

visited[ord(graph[0][0])-ord('A')] = True

# 백트레킹
def dfs(now_y, now_x, cnt):
    global answer
    answer = max(answer, cnt)
    
    for i in range(4):
        ny = now_y + dy[i]
        nx = now_x + dx[i]
        if 0<=ny<r and 0<=nx<c and visited[ord(graph[ny][nx])-ord('A')] == False:
        
            visited[ord(graph[ny][nx])-ord('A')] = True
            dfs(ny, nx, cnt+1)
            visited[ord(graph[ny][nx])-ord('A')] = False

dfs(0, 0, 1)
print(answer)