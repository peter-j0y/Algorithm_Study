import sys
sys.setrecursionlimit(int(1e9))

input = sys.stdin.readline

n, w = map(int, input().split())

tree = [[] for _ in range(n+1)]

for _ in range(n-1):
    u, v = map(int, input().split())
    tree[u].append(v)
    tree[v].append(u)

visited = [False]*(n+1)
leaf_cnt = 0

def dfs(now):
    global leaf_cnt
    visited[now] = True
    is_leaf = True

    for node in tree[now]:

        if visited[node] == False:
            is_leaf = False
            dfs(node)
    
    if is_leaf == True:
        leaf_cnt += 1

dfs(1)

print("%f" %(w/leaf_cnt))