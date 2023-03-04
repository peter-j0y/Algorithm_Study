import sys

input = sys.stdin.readline

n = int(input())

# board[i] = j는 i번째 줄에는 j번째 칸에 퀸을 놓겠다는 뜻
board = [0] * n
ans = 0

def check(x):
    for i in range(x):
        if board[i] == board[x] or abs(board[x] - board[i]) == x - i:
            return False
    return True

def dfs(x):
    global ans

    if x == n:
        ans += 1
        return
    
    else:
        for i in range(n):
            board[x] = i
            if check(x):
                dfs(x+1)

dfs(0)

print(ans)