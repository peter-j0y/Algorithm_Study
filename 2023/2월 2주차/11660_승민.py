# python3는 시간초과, pypy는 통과하는 코드
import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

n, m = map(int, input().split())

a = [list(map(int, input().split())) for _ in range(n)]

m_a = [list(map(int, input().split())) for _ in range(m)]

d = [[0]*(n+1) for _ in range(n+1)]

# O(n^2) 1000*1000 = 1000000
for i in range(1, n+1):
    for j in range(1, n+1):
        if j == 1:
            d[i][j] = a[i-1][j-1]
        else:
            d[i][j] = a[i-1][j-1] + d[i][j-1]

# 100000 * 1000 = 100,000,000
for i in range(m):
    ans = 0

    x1, y1, x2, y2 = m_a[i]

    for j in range(x1, x2 + 1):
        ans += (d[j][y2] - d[j][y1-1])
    
    print(ans)
