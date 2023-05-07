import sys
from collections import deque

input = sys.stdin.readline

t = int(input())
for _ in range(t):

    n, k = map(int, input().split())
    # 건물 건설에 걸리는 시간
    value = [0] + list(map(int, input().split()))
    # dp[i]는 i번째 건물까지 도달하는데에 걸리는 시간
    dp = [0] * (n+1)
    graph = [[] for _ in range(n+1)]
    # 진입차수 저장하는 배열
    indegree = [0] * (n+1)
    
    for _ in range(k):
        x, y = map(int, input().split())
        graph[x].append(y)
        indegree[y] += 1
    
    # 승리를 위해 지어야 하는 건물
    dest = int(input())

    queue = deque([])

    for i in range(1, n+1):
        if indegree[i] == 0:
            queue.append(i)

    while queue:
        out = queue.popleft()
        for elem in graph[out]:
            if dp[out] + value[out] > dp[elem]:
                dp[elem] = dp[out] + value[out]

            indegree[elem] -= 1
            if indegree[elem] == 0:
                queue.append(elem)

    print(dp[dest] + value[dest])