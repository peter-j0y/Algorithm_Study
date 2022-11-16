import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
answer = [0] * N

for i in range(N):
    num = i + 1
    count = 0
    for j in range(N):
        if answer[j] == 0:
            count += 1
            if count == arr[i] + 1:
                answer[j] = num

print(' '.join(map(str, answer)))
