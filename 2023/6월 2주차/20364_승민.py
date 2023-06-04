import sys

input = sys.stdin.readline

n, q = map(int, input().split())
visited = [False]*(n+1)

for _ in range(q):
    val = int(input())
    parent = val
    # 이미 점유된 땅
    v = -1
    while True:
        # "오리가 원하는 땅까지 가는 길에는 오리가 원하는 땅도 포함된다" 조건때문에 먼저 와야함
        if visited[parent]:
            v = parent
        parent //= 2
        if parent == 1:
            visited[val] = True
            break

    if v == -1:
        print(0)
    else:
        print(v)