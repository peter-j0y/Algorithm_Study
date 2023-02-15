import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

n = int(input())

t = []
p = []

for i in range(n):
    ti, pi = map(int, input().split())
    t.append(ti)
    p.append(pi)

dp = [0] * (n+1)
# k는 현재까지의 수익
k = 0

for i in range(n):
    k = max(k, dp[i])
    if i + t[i] > n:
        continue
    dp[i + t[i]] = max(k + p[i], dp[i + t[i]])

print(max(dp))
