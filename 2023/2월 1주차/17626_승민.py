import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

b = 10

n = int(input())

d = [b] * (n+1)

for i in range(1, int(n**(1/2))+1) :
    d[i*i] = 1

for i in range(2, n+1):
    if d[i] == b:
        for j in range(1, int(i**(1/2))+1):
            d[i] = min(d[i], 1+d[i - j*j])

print(d[n])
