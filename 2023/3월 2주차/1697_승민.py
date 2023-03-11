import sys
from collections import deque

sys.setrecursionlimit(int(1e9))

input = sys.stdin.readline

n, k = map(int, input().split())
q = deque()
visited = [False]*(100001)
q.append([n, 0])
print(q)

while(q):
    now, cnt = q.popleft()
    visited[now] = True

    if now == k:
        print(cnt)
        break

    for nx in (now-1, now+1, now*2):
        if 0<=nx<=100000 and visited[nx]==False:
            q.append([nx, cnt+1])
