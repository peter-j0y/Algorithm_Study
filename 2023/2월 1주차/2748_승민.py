import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

d = [0] * 91

d[0] = 0
d[1] = 1

n = int(input())

for i in range(2, n+1):
    d[i] = d[i-1] + d[i-2]

print(d[n])
