import sys
from collections import deque

sys.setrecursionlimit(10000)
input = sys.stdin.readline

n = int(input())
m = int(input())

graph = [[] for _ in range(n+1)]
basic = []

for _ in range(m):
    x, y, k = map(int, input().split())
    graph[x].append([y, k])

dp = [[0] * (n+1) for _ in range(n+1)]
queue = deque([])
indegree = [0] * (n+1)

for i in range(n+1):
    indegree[i] += len(graph[i])
    if not graph[i]:
        basic.append(i)

for i in range(1, n+1):
    if indegree[i] == 0:
        queue.append(i)

while queue:
    now = queue.popleft()
    
    for i in range(n+1):
        for j in range(len(graph[i])):
            if graph[i][j][0] == now:
                indegree[i] -= 1
                if indegree[i] == 0:
                    queue.append(i)
                break

    for i, j in graph[now]:
        if i in basic:
            dp[now][i] += j 
        else:
            for idx, elem in enumerate(dp[i]):
                dp[now][idx] += j * elem

for idx, elem in enumerate(dp[n]):
    if elem != 0:
        print(idx, elem)
