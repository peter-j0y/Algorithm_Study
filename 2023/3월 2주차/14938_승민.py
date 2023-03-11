import sys

input = sys.stdin.readline

# 1<=n<=100, 1<=m<=15, 1<=r<=100
n, m, r = map(int, input().split())

area = [0] + list(map(int, input().split()))

ans = [0] * (n+1)

INF = int(1e9)
graph = [[INF] * (n+1) for _ in range(n+1)]

for _ in range(r):
    a, b, l = map(int, input().split())
    graph[a][b] = l
    graph[b][a] = l

for i in range(1, n+1):
    for j in range(1, n+1):
        for k in range(1, n+1):
            if i != j and j != k:
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k])

ans = 0
for i in range(1, n+1):
    temp = 0
    for j in range(1, n+1):
        if i == j:
            temp += area[i]
        else:
            if graph[i][j] <= m:
                temp += area[j]
    ans = max(ans, temp)

print(ans)