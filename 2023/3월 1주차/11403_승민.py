import sys
import heapq

input = sys.stdin.readline

n = int(input())

al = [list(map(int, input().split())) for _ in range(n)]

INF = int(1e9)
ans = [[] for _ in range(n)]

def dijkstra(start) :
    q = []
    dist = [INF] * n

    heapq.heappush(q, [0, start])

    while q:
        dis, now = heapq.heappop(q)

        for idx, elem in enumerate(al[now]):
            if elem == 1 and dist[idx] > dis + 1:
                dist[idx] = dis + 1
                heapq.heappush(q, [dist[idx], idx])

    for idx, elem in enumerate(dist):
        if elem != INF:
            ans[start].append(1)
        else:
            ans[start].append(0)

for i in range(n):
    dijkstra(i)

for i in range(n):
    for j in range(n):
        print(ans[i][j], end = ' ')
    print()