import sys
import heapq

input = sys.stdin.readline

INF = int(1e9)

n, w = map(int, input().split())

m = float(input())

c = [[]]
graph = [[INF]*(n+1) for _ in range(n+1)]

# O(n) 1000
for _ in range(n):
    x, y = map(int, input().split())
    c.append([x, y])

# O(w) 10000
for _ in range(w):
    a, b = map(int, input().split())
    graph[a][b] = 0
    graph[b][a] = 0

# O(n^2) 1,000,000
for i in range(1, n+1):
    for j in range(i+1, n+1):
        d = ((c[i][0]-c[j][0])**2 + (c[i][1]-c[j][1])**2)**(1/2)
        if graph[i][j] != 0 and d <= m:
            graph[i][j] = d
            graph[j][i] = d

dist = [INF]*(n+1)
dist[1] = 0

q = []
heapq.heappush(q, [1, 0])

while q:
    now, dis = heapq.heappop(q)
    for idx, elem in enumerate(graph[now]):
        if dist[idx] > dis + elem:
            dist[idx] = dis + elem
            heapq.heappush(q, [idx, dist[idx]])

print(int(dist[n]*1000))