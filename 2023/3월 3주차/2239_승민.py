import sys

input = sys.stdin.readline

graph = []
zero = []

for _ in range(9):
    graph.append(list(input().rstrip()))

for i in range(9):
    for j in range(9):
        graph[i][j] = int(graph[i][j])
        if graph[i][j] == 0:
            zero.append([i, j])

def check(x, y, i):
    for k in range(9):
        if graph[y][k] == i:
            return False
    
    for k in range(9):
        if graph[k][x] == i:
            return False
    
    nx = x // 3 * 3 # 0, 1, 2 -> 0, 3, 4, 5 -> 1, 6, 7, 8 -> 2
    ny = y // 3 * 3

    for k in range(ny, ny+3):
        for l in range(nx, nx+3):
            if graph[k][l] == i:
                return False
    
    return True

def dfs(l):
    if l == len(zero):
        for i in range(9):
            for j in range(9):
                print(graph[i][j], end = '')
            print()
            
        exit()
    
    y, x = zero[l]
    for i in range(1, 10):
        if check(x, y, i):
            graph[y][x] = i
            dfs(l+1)
            graph[y][x] = 0

dfs(0)
