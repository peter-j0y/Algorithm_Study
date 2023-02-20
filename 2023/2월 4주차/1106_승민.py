import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

# c <= 1000, n <= 20
c, n = map(int, input().split())

data = []

for _ in range(n):
    data.append(list(map(int, input().split())))

INF = 10e9
dp = [INF] * (c+101)
dp[0] = 0

for cost, customer in data:
    for i in range(customer, c+101):
        dp[i] = min(dp[i], dp[i-customer] + cost)

print(min(dp[c:]))
