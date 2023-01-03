import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

# 오름차순으로 정렬한 뒤 투포인터를 써서 포인터가 가리키는 원소의 합의 절댓값을
# 구한 뒤 가장 작은 값을 구해서 답을 구하면 됨

N = int(input())

arr = list(map(int, input().split()))
arr.sort()

min_sum = 10e9
temp_front_answer_idx = 0
temp_back_answer_idx = N-1

front_pt_idx = 0
back_pt_idx = N-1

while front_pt_idx < back_pt_idx:
    temp_sum = arr[front_pt_idx] + arr[back_pt_idx]

    if min_sum > abs(temp_sum) :
        min_sum = abs(temp_sum)
        temp_front_answer_idx = front_pt_idx
        temp_back_answer_idx = back_pt_idx

    if temp_sum < 0 :
        front_pt_idx += 1
    elif temp_sum > 0 :
        back_pt_idx -= 1
    else :
        break

print(arr[temp_front_answer_idx], arr[temp_back_answer_idx])
