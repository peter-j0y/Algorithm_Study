import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

n = int(input())

sea = []
bea = []

for _ in range(n-1):
    se, be = map(int, input().split())
    sea.append(se)
    bea.append(be)

k = int(input())

ans = 10e9

for i in range(3, n):
    d = [0] * n
    d[1] = sea[0]
    for j in range(2, n):
        if i == j:
            d[j] = min(k + d[j-3], d[j-1] + sea[j-1], d[j-2] + bea[j-1])
        else:
            d[j] = min(d[j-1] + sea[j-1], d[j-2] + bea[j-1])
    ans = min(ans, d[n-1])

print(ans)
