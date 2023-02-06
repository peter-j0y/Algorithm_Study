import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

n = int(input())

a = [list(map(int, input().split())) for _ in range(n)]

d = [[0] * n for _ in range(n)]

d[0][0] = 1

answer = 0

for i in range(n):
    for j in range(n):

        if i == n-1 and j == n-1:
            break

        if i + a[i][j] < n:
            d[i+a[i][j]][j] += d[i][j]
            if i + a[i][j] == n - 1 and j == n - 1:
                answer += d[i][j]

        if j + a[i][j] < n:
            d[i][j+a[i][j]] += d[i][j]
            if i == n - 1 and j + a[i][j] == n - 1:
                answer += d[i][j]

print(d[n-1][n-1])
