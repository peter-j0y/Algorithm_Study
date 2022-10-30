import sys
import heapq
sys.setrecursionlimit(10000)
input = sys.stdin.readline

# 문제를 처음 보고 든 생각
# 음 단방향 그래프 문제군~
# 1부터 N까지 X까지 가는 최단거리들을 구한다음에 최댓값을 구하면 되겠는걸?
# dfs로 어찌저찌하면 되지 않을까
# 이거 너무 안되는데? 뭔가 잘못됨을 느낌 -> 문제 검색해봄 -> 다익스트라가 있지..

INF = 10e9

N, M, X = map(int, input().split())
graph = [[] for _ in range(N+1)]

for i in range(M):
    s, e, v = map(int, input().split())
    graph[s].append([e, v])

def dijkstra(start, dest):
    distance = [INF]*(N+1)
    priority_q = []
    distance[start] = 0
    heapq.heappush(priority_q, (0, start))
    while priority_q:
        dist, now = heapq.heappop(priority_q)
        if dist > distance[now]:
            continue
        for i in graph[now]:
            if dist + i[1] < distance[i[0]]:
                distance[i[0]] = dist + i[1]
                heapq.heappush(priority_q, (distance[i[0]], i[0]))
    return distance[dest]

answer = 0
for i in range(1, N+1):
    if i != X:
        answer = max(answer, dijkstra(i, X) + dijkstra(X, i))

print(answer)
