import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

d = [[1] * 101 for _ in range(101)]

n, m = map(int, input().split())

for i in range(2, n+1):
    for j in range(1, m+1):
        if j!=0 and i!=j:
            d[i][j] = d[i-1][j-1] + d[i-1][j]

print(d[n][m])
