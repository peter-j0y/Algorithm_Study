import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

N = int(input())

A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort(reverse=True)
B.sort()

answer = 0
for i in range(N):
    answer += A[i] * B[i]

print(answer)
