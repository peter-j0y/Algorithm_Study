import sys

input = sys.stdin.readline

n, m = map(int, input().split())

arr = list(map(int, input().split()))

arr.sort()
q = []
visited = [False] * n

def dfs(l):
    if l == m:
        print(' '.join(map(str, q)))
        return
    
    for i in range(n):
        if visited[i] == False:
            q.append(arr[i])
            visited[i] = True
            dfs(l + 1)
            visited[i] = False
            q.pop()

dfs(0)