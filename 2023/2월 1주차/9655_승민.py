import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

d = [0] * 1001

n = int(input())

d[1] = 1
d[3] = 1

for i in range(2, n+1):
    if d[i] == 0:
        d[i] = d[i-1] + 1

if d[n] % 2 == 0:
    print("CY")
else:
    print("SK")
