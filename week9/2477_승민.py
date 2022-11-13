import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

K = int(input())
arr = []
w = 0
w_idx = 0
h = 0
h_idx = 0

for i in range(6):
    # d는 방향, l은 길이
    d, l = map(int, input().split())
    arr.append([d, l])
    if d == 3 or d == 4 :
        if w < l :
            w = l
            w_idx = i
    if d == 1 or d == 2 :
        if h < l :
            h = l
            h_idx = i
# s_w는 작은 사각형 너비, s_h는 큰 사각형 높이
# 큰 사각형의 너비와 높이 인덱스를 이용해서 작은 사각형의 너비와 높이 구함
s_w = w - min(arr[(h_idx + 1) % 6][1], arr[h_idx - 1][1])
s_h = h - min(arr[(w_idx + 1) % 6][1], arr[w_idx - 1][1])
s = w*h - s_w*s_h
print(K * s)
