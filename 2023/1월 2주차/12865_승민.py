import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

n, k = map(int, input().split())

stuff = [[0, 0]]
knapsack = [[0 for _ in range(k + 1)] for _ in range(n + 1)]

for i in range(n):
    stuff.append(list(map(int, input().split())))

for i in range(1, n+1):
    for j in range(1, k+1):
        w = stuff[i][0]
        v = stuff[i][1]

        # 만약 물건의 무게가 가방에 담을 수 없다면
        if j < w:
            knapsack[i][j] = knapsack[i-1][j]
        # 물건을 가방에 담을 수 있다면 물건을 담는 경우와 담지 않았을 경우 중 큰 값을 저장
        else:
            knapsack[i][j] = max(knapsack[i-1][j-w] + v, knapsack[i-1][j])

print(knapsack[n][k])
