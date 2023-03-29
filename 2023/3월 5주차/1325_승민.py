import sys
from collections import deque

input = sys.stdin.readline

# 1 <= n <= 10,000 1 <= m <= 100,000
n, m = map(int, input().split())

graph = [[] for _ in range(n+1)]
answer = []

max_hacking = 0

for _ in range(m):
    a, b = map(int, input().split())
    graph[b].append(a)

def bfs(start):
    visited = [False] * (n+1)
    queue = deque([start])
    visited[start] = True
    hacking_cnt = 1

    while queue:
        node = queue.popleft()

        for elem in graph[node]:
            if visited[elem] == False:
                queue.append(elem)
                visited[elem] = True
                hacking_cnt += 1

    return hacking_cnt

for i in range(1, n+1):
    bfs_res = bfs(i)

    if bfs_res > max_hacking:
        max_hacking = bfs_res
        answer.clear()
        answer.append(i)
    
    elif bfs_res == max_hacking:
        answer.append(i)

print(*answer)