import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

# 첫 네모를 사분면으로 나누어서 어떤 사분면에 속하는지 파악한 다음 해당 사분면을
# 첫 사각형으로 다시 생각해 r과 c값을 조정한 후 N이 1일 때까지 반복적으로 위치를 구함

N, r, c = map(int, input().split())

answer = 0

while N >= 1:
    inner_len = 2 ** (N-1)
    if r < inner_len and c < inner_len:
        answer += 0
    elif r < inner_len and c >= inner_len:
        answer += (inner_len * inner_len)
        c -= inner_len
    elif r >= inner_len and c < inner_len:
        answer += 2*(inner_len * inner_len)
        r -= inner_len
    else :
        answer += 3*(inner_len * inner_len)
        c -= inner_len
        r -= inner_len
    N -= 1

print(answer)
