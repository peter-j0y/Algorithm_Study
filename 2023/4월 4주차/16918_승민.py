import sys

input = sys.stdin.readline

r, c, n = map(int, input().split())

graph = [list(input().rstrip()) for _ in range(r)]

graph_time = []

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for i in range(r):
    time_arr = []
    for j in range(c):
        if graph[i][j] == '.':
            time_arr.append(0)
        elif graph[i][j] == 'O':
            time_arr.append(2)
    graph_time.append(time_arr)


for _ in range(1, n):
    temp_bomb = []

    for i in range(r):
        for j in range(c):
            if graph_time[i][j] == 3:
                temp_bomb.append([i, j])
            else:
                graph_time[i][j] += 1

    for elem in temp_bomb:
        y, x = elem[0], elem[1]
        graph_time[y][x] = 0
        
        for k in range(4):
            ny = y+dy[k]
            nx = x+dx[k]
            if 0<=ny<r and 0<=nx<c:
                graph_time[ny][nx] = 0

for i in range(r):
    for j in range(c):
        if graph_time[i][j] == 0:
            print('.', end='')
        else:
            print('O', end='')
    print()