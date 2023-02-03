import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

n = int(input())

a = list(map(int, input().split()))

d = a[:]

for i in range(n):
    ti = -1
    tv = 0

    for j in range(i-1, -1, -1):
        if tv < d[j]  and a[j] < a[i]:
            tv = d[j]
            ti = j

    if ti != -1:
        d[i] += tv

print(max(d))
