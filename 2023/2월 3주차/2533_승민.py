import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

n = int(input())

graph = [[] for _ in range(n+1)]

for _ in range(n-1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

# dp[index][1] 얼리어댑터인 경우 -> 자식이 얼리어댑터여도 되고 아니어도 된다.
# dp[index][0] 얼리어댑터가 아닌 경우 -> 자식이 모두 얼리어댑터여야 한다.
dp = [[0, 1] for _ in range(n+1)]

visited = [False] * (n+1)

def dfs(num):
    visited[num] = True
    
    for i in graph[num]:
        if not visited[i]:
            dfs(i)
            dp[num][0] += dp[i][1]
            dp[num][1] += min(dp[i][0], dp[i][1])

dfs(1)
print(min(dp[1][0], dp[1][1]))
