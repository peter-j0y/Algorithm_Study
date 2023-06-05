import sys

input = sys.stdin.readline

def check(start_row, start_col, row, col, arr):
    for i in range(row):
        for j in range(col):
            if arr[i][j] == 1 and board[i+start_row][j+start_col] != 0:
                return False
    return True

def rotate(arr, row, col):
    new_arr = []
    for i in range(col):
        temp = []
        for j in range(row):
            temp.append(arr[row-j-1][i])
        new_arr.append(temp)
    return new_arr

n, m, k = map(int, input().split())
board = [[0]*m for _ in range(n)]

for _ in range(k):
    r, c = map(int, input().split())
    sticker = [list(map(int, input().split())) for _ in range(r)]

    isSticked = False
    for _ in range(4):
        if r > n or c > m:
            sticker = rotate(sticker, r, c)
            r,c = c,r
            continue

        for i in range(n-r+1):
            if isSticked:
                break
            for j in range(m-c+1):
                if isSticked:
                    break
                if check(i, j, r, c, sticker):
                    for k in range(i, i+r):
                        for l in range(j, j+c):
                            if sticker[k-i][l-j] == 1:
                                board[k][l] = 1
                    isSticked = True

        if isSticked:
            break
        sticker = rotate(sticker, r, c)
        r,c = c,r 

answer = 0
for elem in board:
    answer += elem.count(1)

print(answer)