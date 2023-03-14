import sys

input = sys.stdin.readline

n, m = map(int, input().split())

arr = [[0] * (m+1) for _ in range(n+1)]
answer = 0

def dfs(x, y):
    global answer

    # 종료 조건
    if x == 1 and y == n+1:
        answer += 1
        return
    
    # x가 행의 끝에 도달했을 때
    if x == m:
        nx, ny = 1, y+1
    # x가 행의 끝이 아닐 때
    else:
        nx, ny = x+1, y
    
    # 넴모를 놓지 않는 경우
    dfs(nx, ny)
    
    # 넴모를 놓는 경우
    if arr[y-1][x] == 0 or arr[y][x-1] == 0 or arr[y-1][x-1] == 0:
        arr[y][x] = 1
        dfs(nx, ny)
        arr[y][x] = 0

dfs(1, 1)

print(answer)