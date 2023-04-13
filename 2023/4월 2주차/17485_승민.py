import sys

input = sys.stdin.readline

n, m = map(int, input().split())
INF = int(1e5)
arr = [list(map(int, input().split())) for _ in range(n)]
dp = [[[INF] * 3 for _ in range(m)] for _ in range(n)]

for i in range(n):
    for j in range(m):

        if i == 0:
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = arr[i][j]
            continue

        dp[i][j][1] = arr[i][j] + min(dp[i-1][j][0], dp[i-1][j][2])

        if j == 0:
            dp[i][j][0] = arr[i][j] + min(dp[i-1][j+1][1], dp[i-1][j+1][2])

        elif j == m-1:
            dp[i][j][2] = arr[i][j] + min(dp[i-1][j-1][0], dp[i-1][j-1][1])

        else:
            dp[i][j][0] = arr[i][j] + min(dp[i-1][j+1][1], dp[i-1][j+1][2])
            dp[i][j][2] = arr[i][j] + min(dp[i-1][j-1][0], dp[i-1][j-1][1])

answer = int(1e9)
for i in range(m):
    answer = min(answer, min(dp[n-1][i]))

print(answer)