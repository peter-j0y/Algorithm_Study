import sys
import heapq

input = sys.stdin.readline

n, m = map(int, input().split())

graph = [list(map(int, input().split())) for _ in range(n)]
short_arr = []

INF = int(1e9)

def dijkstra(line):
    dist = [INF] * n
    q = []
    
    heapq.heappush(q, [0, line-1])

    while q:
        dis, now = heapq.heappop(q)

        for idx, d in enumerate(graph[now]):
            if dis + d < dist[idx]:
                dist[idx] = dis + d
                heapq.heappush(q, [dist[idx], idx])
        
    short_arr.append(dist)

for i in range(1, n+1):
    dijkstra(i)

for _ in range(m):
    a, b, c = map(int, input().split())

    if short_arr[a-1][b-1] <= c:
        print("Enjoy other party")

    else:
        print("Stay here")
