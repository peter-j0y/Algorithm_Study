import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline


n = int(input())

dp = [0] * (n+1)

dp[1] = 1

# 타일이 놓일 수 있는 경우는 2가지 -> 세로인 상태로 1개가 놓이거나 가로인 상태로 2개가 놓이거나
# 즉 i번째 경우의 수에서 i-1번째 경우의 수에 세로 블록 1개를 놓거나 i-2번째 경우의 수에 가로 블록을 2개 놓아야함
# 이를 점화식으로 표현하면 dp[i] = dp[i-1] + dp[i-2]
# 범위 조심 n 값이 1, 2인 경우도 항상 생각해야함
if n >= 2:
    dp[2] = 2
    for i in range(3, n+1):
        dp[i] = (dp[i-1] + dp[i-2]) % 10007

print(dp[n] % 10007)
