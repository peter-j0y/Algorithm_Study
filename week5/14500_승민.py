import sys
input = sys.stdin.readline

n, m = map(int, input().split())
answer = 0

board = [list(map(int, input().split())) for _ in range(n)]

def shape1(x, y) :
    global answer
    if 0<=x<m and 0<=x+3<m :
        sum = board[y][x] + board[y][x+1] + board[y][x+2] + board[y][x+3]
        if sum > answer :
            answer = sum
    
    if 0<=y<n and 0<=y+3<n:
        sum = board[y][x] + board[y+1][x] + board[y+2][x] + board[y+3][x]
        if sum > answer :
            answer = sum

def shape2(x, y) :
    global answer
    if 0<=x<m and 0<=x+1<m and 0<=y<n and 0<=y+1<n:
        sum = board[y][x] + board[y][x+1] + board[y+1][x] + board[y+1][x+1]
        if sum > answer :
            answer = sum

def shape3(x, y) :
    global answer
    if 0<=x<m and 0<=x+1<m and 0<=y<n and 0<=y+2<n:
        sum = board[y][x] + board[y+1][x] + board[y+2][x] + board[y+2][x+1]
        if sum > answer :
            answer = sum
        sum = board[y][x] + board[y][x+1] + board[y+1][x+1] + board[y+2][x+1]
        if sum > answer :
            answer = sum

    if 0<=x<m and 0<=x+2<m and 0<=y<n and 0<=y+1<n:
        sum = board[y][x] + board[y+1][x] + board[y][x+1] + board[y][x+2]
        if sum > answer :
            answer = sum
    if 0<=x<m and 0<=x+2<m and 0<=y<n and 0<=y-1<n:  
        sum = board[y][x] + board[y][x+1] + board[y][x+2] + board[y-1][x+2]
        if sum > answer :
            answer = sum

    if 0<=x<m and 0<=x-1<m and 0<=y<n and 0<=y+2<n:  
        sum = board[y][x] + board[y+1][x] + board[y+2][x] + board[y+2][x-1]
        if sum > answer :
            answer = sum
    
    if 0<=x<m and 0<=x+2<m and 0<=y<n and 0<=y+1<n:  
        sum = board[y][x] + board[y][x+1] + board[y][x+2] + board[y+1][x+2]
        if sum > answer :
            answer = sum

    if 0<=x<m and 0<=x+1<m and 0<=y<n and 0<=y+2<n:  
        sum = board[y][x] + board[y][x+1] + board[y+1][x] + board[y+2][x]
        if sum > answer :
            answer = sum

    if 0<=x<m and 0<=x+2<m and 0<=y<n and 0<=y+1<n:  
        sum = board[y][x] + board[y+1][x] + board[y+1][x+1] + board[y+1][x+2]
        if sum > answer :
            answer = sum

    if 0<=x<m and 0<=x-1<m and 0<=y<n and 0<=y+2<n:  
        sum = board[y][x] + board[y+1][x] + board[y+1][x-1] + board[y+2][x-1]
        if sum > answer :
            answer = sum

    if 0<=x<m and 0<=x+2<m and 0<=y<n and 0<=y+1<n:  
        sum = board[y][x] + board[y][x+1] + board[y+1][x+1] + board[y+1][x+2]
        if sum > answer :
            answer = sum

def shape4(x, y) :
    global answer
    if 0<=x<m and 0<=x+1<m and 0<=y<n and 0<=y+2<n:
        sum = board[y][x] + board[y+1][x] + board[y+1][x+1] + board[y+2][x+1]
        if sum > answer :
            answer = sum
    
    if 0<=x<m and 0<=x+2<m and 0<=y<n and 0<=y-1<n:
        sum = board[y][x] + board[y][x+1] + board[y-1][x+1] + board[y-1][x+2]
        if sum > answer :
            answer = sum

def shape5(x, y) :
    global answer
    if 0<=x<m and 0<=x+2<m and 0<=y<n and 0<=y+1<n:
        sum = board[y][x] + board[y][x+1] + board[y][x+2] + board[y+1][x+1]
        if sum > answer :
            answer = sum
    
    if 0<=x<m and 0<=x+1<m and 0<=y-1<n and 0<=y+1<n:
        sum = board[y][x] + board[y][x+1] + board[y+1][x+1] + board[y-1][x+1]
        if sum > answer :
            answer = sum

    if 0<=x<m and 0<=x+2<m and 0<=y<n and 0<=y-1<n:
        sum = board[y][x] + board[y][x+1] + board[y][x+2] + board[y-1][x+1]
        if sum > answer :
            answer = sum

    if 0<=x<m and 0<=x+1<m and 0<=y<n and 0<=y+2<n:
        sum = board[y][x] + board[y+1][x] + board[y+1][x+1] + board[y+2][x]
        if sum > answer :
            answer = sum

for i in range(n) :
    for j in range(m) :
        shape1(j, i)
        shape2(j, i)
        shape3(j, i)
        shape4(j, i)
        shape5(j, i)

print(answer)
