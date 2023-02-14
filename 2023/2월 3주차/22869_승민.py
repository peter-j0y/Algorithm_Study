import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

n, k = map(int, input().split())

stone = list(map(int, input().split()))

dp = [[False] * n for _ in range(n)]

for i in range(n):
    for j in range(i+1, n):
        if (j - i) * (1 + abs(stone[i] - stone[j])) <= k:
            dp[i][j] = True

dp2 = [False] * n
dp2[0] = True

for idx, elem in enumerate(dp2):
    if elem == True:
        for i in range(idx+1, n):
            if dp[idx][i] == True:
                dp2[i] = True

if dp2[n-1] == True:
    print('YES')
else:
    print('NO')
