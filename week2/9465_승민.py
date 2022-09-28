import sys
input = sys.stdin.readline

def solution():
    n = int(input())
    stickers = [list(map(int, input().split())) for _ in range(2)]
    dp = [[0] * n for _ in range(2)]
    dp[0][0] = stickers[0][0]
    dp[1][0] = stickers[1][0]
    if n > 1:
        dp[0][1] = stickers[0][1] + dp[1][0]
        dp[1][1] = stickers[1][1] + dp[0][0]

    if n >= 2:
        for i in range(2, n):
            for j in range(2):
                if j == 0:
                    dp[j][i] = max(dp[j+1][i-1], dp[j+1][i-2]) + stickers[j][i]
                if j == 1:
                    dp[j][i] = max(dp[j-1][i-1], dp[j-1][i-2]) + stickers[j][i]
    print(max(map(max, dp)))
    
T = int(input())
for _ in range(T):
    solution()