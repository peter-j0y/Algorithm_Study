import sys

input = sys.stdin.readline

n = int(input())
m = int(input())

graph = [[False] * (n+1) for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b] = True

for i in range(1, n+1):
    for j in range(1, n+1):
        for k in range(1, n+1):

            if graph[j][k] == True:
                continue

            if j == k:
                graph[j][k] = True
                continue

            if graph[j][i] == True and graph[i][k] == True:
                graph[j][k] = True

for i in range(1, n+1):
    for j in range(1, n+1):
        if graph[i][j] == True:
            graph[j][i] = True
            
for i in range(1, n+1):
    cnt = 0

    for j in range(1, n+1):
        if graph[i][j] == False:
            cnt += 1
    
    print(cnt)