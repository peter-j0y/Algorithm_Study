import sys
input = sys.stdin.readline

def dfs(now, count):
    global answer
    if count == n//2:
        team_a, team_b = 0, 0
        for i in range(n):
            for j in range(n):
                if visited[i] and visited[j]:
                    team_a += graph[i][j]
                elif not visited[i] and not visited[j]:
                    team_b += graph[i][j]

        answer = min(answer, abs(team_a-team_b))
    
    for i in range(now, n):
        if visited[i]:
            continue
        visited[i] = 1
        dfs(i+1, count+1)
        visited[i] = 0

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
visited = [0 for _ in range(n)]
answer = sys.maxsize

dfs(0, 0)
print(answer)