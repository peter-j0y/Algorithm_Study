import sys
import heapq

sys.setrecursionlimit(10000)
input = sys.stdin.readline

n, m, k, x = map(int, input().split())

graph = [[] for _ in range(n+1)]
INF = 10e9
dist = [INF] * (n+1)
res = []

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

q = []
heapq.heappush(q, (0, x))
dist[x] = 0

while q:
    dis, now = heapq.heappop(q)
    if dis > dist[now]:
        continue
    for elem in graph[now]:
        if dis + 1 < dist[elem]:
            dist[elem] = dis + 1
            heapq.heappush(q, (dis+1, elem))

for idx, elem in enumerate(dist):
    if elem == k:
        res.append(idx)

if res:
    for elem in res:
        print(elem)

else:
    print(-1)
