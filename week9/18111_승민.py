import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

N, M, B = map(int, input().split())

ground = [list(map(int, input().split())) for _ in range(N)]

# 땅 중에 가장 낮은 땅, 높은 땅
s = min(map(min, ground))
l = max(map(max, ground))    

answer = 10e9
min_h = 0

for idx in range(s, l+1):
    # 파야 되는 땅의 양
    d = 0
    # 채워야되는 땅의 양
    u = 0
    # 가지고 있는 블럭

    for i in range(N):
        for j in range(M):
            diff = ground[i][j] - idx
            # 땅의 높이가 더 높으면
            if diff > 0:
                d += diff
            # 땅을 메워야 하면
            if diff < 0:
                u -= diff
    if B + d < u:
        continue
    time = 2*d + u

    if time <= answer:
        answer = time
        if min_h < idx:
            min_h = idx

print(answer, min_h)
