import sys

input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

min_diff = int(1e10)
answer_a = 0
answer_b = 0

def binary_search(i):
    global answer_a, answer_b, min_diff
    st = i+1
    ed = n-1
    num = arr[i]

    while st <= ed:
        mid = (st+ed)//2
        temp = arr[mid] + num
        if abs(temp) < min_diff:
            min_diff = abs(temp)
            answer_a = num
            answer_b = arr[mid]

            if temp == 0:
                return
        
        if temp > 0:
            ed = mid - 1
        else:
            st = mid + 1
    return

for i in range(n-1):
    binary_search(i)

print(answer_a, answer_b)