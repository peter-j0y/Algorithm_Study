import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

# 1<=n<=100, 1<=k<=10,000
n, k = map(int, input().split())

coin = []

# 동전<=100,000
for _ in range(n):
    coin.append(int(input()))

INF = 10e9
dp = [INF] * (k+1)
dp[0] = 0

for c in coin:
    for i in range(c, k+1):
        dp[i] = min(dp[i], dp[i-c] + 1)

if dp[k] == INF:
    print(-1)
else:
    print(dp[k])
