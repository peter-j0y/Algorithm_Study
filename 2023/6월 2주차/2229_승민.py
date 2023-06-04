import sys

input = sys.stdin.readline

# 1<=n<=1000
n = int(input())

score = [0] + list(map(int, input().split()))
# dp[i]는 i명으로 조를 짤 때 나올 수 있는 최댓값
dp = [0] * (n+1)

for i in range(2, n+1):
    for j in range(i-1, -1, -1):
        dp[i] = max(dp[i], dp[j] + max(score[j+1:i+1]) - min(score[j+1:i+1]))

print(dp[n])