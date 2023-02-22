import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

n = int(input())

graph = [[0] * n for _ in range(n)]

f = []
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

for _ in range(n*n):
    f.append(list(map(int, input().split())))

for e in f:
    c = e[0]
    friends = e[1:]
    temp_x = -1
    temp_y = -1
    max_like = -1
    max_empty = -1

    for i in range(n):
        for j in range(n):
            like = -1
            empty = -1
            if graph[i][j] == 0:
                like += 1
                empty += 1
                for k in range(4):
                    nx = j + dx[k]
                    ny = i + dy[k]
                    if 0<= nx < n and 0<= ny < n:
                        if graph[ny][nx] in friends:
                            like += 1
                        if graph[ny][nx] == 0:
                            empty += 1
            


            if like > max_like:
                max_like = like
                max_empty = empty
                temp_x = j
                temp_y = i
            
            elif like == max_like and empty > max_empty:
                max_empty = empty
                temp_x = j
                temp_y = i

            # print("c " + str(c))
            # print("like " + str(like) + " max_like " + str(max_like))
            # print("empty " + str(empty) + " max_empty " + str(max_empty))
            # print("temp_y " + str(temp_y) + " temp_x " + str(temp_x))

    graph[temp_y][temp_x] = c

ans = 0

for e in f:
    c = e[0]
    friends = e[1:]
    num = 0
    
    for i in range(n):
        for j in range(n):
            if graph[i][j] == c:
                for k in range(4):
                    nx = j + dx[k]
                    ny = i + dy[k]
                    if 0<=nx<n and 0<=ny<n:
                        if graph[ny][nx] in friends:
                            num += 1

    if num == 1:
        ans += 1
    elif num == 2:
        ans += 10
    elif num == 3:
        ans += 100
    elif num == 4:
        ans += 1000

print(ans)
