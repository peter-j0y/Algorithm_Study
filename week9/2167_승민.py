import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

N, M = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(N)]

K = int(input())

# 부분합 구하기
for i in range(N):
    for j in range(1, M):
        arr[i][j] += arr[i][j-1]

for _ in range(K):
    answer = 0
    i, j, x, y = map(int, input().split())
    for a in range(i-1, x):
        if j-2>=0:
            answer += arr[a][y-1] - arr[a][j-2]
        else:
            answer += arr[a][y-1]
    print(answer)
