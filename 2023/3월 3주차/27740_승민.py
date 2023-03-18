import sys

input = sys.stdin.readline

n = int(input())

arr = list(map(int, input().split()))

st = 0
end = 0
cnt = 0
for idx in range(n):
    if arr[idx] == 0:
        temp_cnt = 0
        next_idx = idx
        temp_st = idx

        while next_idx < n and arr[next_idx] == 0:
            next_idx += 1
            temp_cnt += 1

        temp_end = next_idx - 1
        idx = next_idx

        if temp_cnt > cnt:
            st = temp_st
            end = temp_end
            cnt = temp_cnt

left = st
right = n - end - 1

ans_str = ""

if cnt == 0:
    answer = n
    ans_str += "L"*n

elif left < right:
    ans_str += "L"*left
    ans_str += "R"*(right + left)
    answer = left*2 + right

else:
    ans_str += "R"*right
    ans_str += "L"*(left + right)
    answer = left + right*2

print(answer)
print(ans_str)