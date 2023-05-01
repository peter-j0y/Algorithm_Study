import sys

input = sys.stdin.readline

n, k = map(int, input().split())
dp = [[0] * (k+1) for _ in range(n+1)]

# 만약 n=20, k=5라면 [0 + (20을 4개로 나눈 것)] + [1 + (19를 4개로 나눈 것)] + [2 + (18를 4개로 나눈 것)] + ... + [20 + (0을 4개로 나눈 것)]
# dp[n][k] = dp[0][k-1] + dp[1][k-1] + ... + dp[n-1][k-1] + dp[n][k-1]
# dp[n-1][k] = dp[0][k-1] + dp[1][k-1] + ... + dp[n-1][k-1] 
# 따라서 dp[n][k] = dp[n-1][k] + dp[n][k-1]
for i in range(1, n+1):
    for j in range(1, k+1):
        if i == 1:
            dp[i][j] = j
            continue

        if j == 1:
            dp[i][j] = 1
        else:
            dp[i][j] =  (dp[i-1][j] + dp[i][j-1]) % 1000000000

print(dp[n][k])