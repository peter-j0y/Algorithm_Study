import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

n = int(input())

s = []
b = []

for _ in range(n-1):
    se, be = map(int, input().split())
    s.append(se)
    b.append(be)

k = int(input())

answer = []

if n >= 3:

    d = [0] * n
    d[1] = s[0]

    for i in range(2, n):
        d[i] = min(d[i-1] + s[i-1], d[i-2] + b[i-2])

    answer.append(d[n-1])

    for i in range(n-3):
        d_copy = d[:]
        d_copy[i+3] = d[i] + k
        for j in range(i+4, n):
            d_copy[j] = min(d_copy[j-1] + s[j-1], d_copy[j-2] + b[j-2])

        answer.append(d_copy[n-1])

    print(min(answer))

elif n == 3:
    print(min(sum(s), b[0]))

elif n == 2:
    print(s[0])

else:
    print(0)
