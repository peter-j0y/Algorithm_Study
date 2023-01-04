import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

N = int(input())

arr = list(map(int, input().split()))

total = int(input())

start = min(arr)
end = max(arr)
total_sum = sum(arr)

# 모든 예산을 다 배정할 수 있는 경우
if total >= total_sum:
    print(end)

# 모든 예산을 배정할 수 없어서 상한산을 정해야 하는 경우
else:
    answer = 0

    while start <= end:
        mid = (start + end) // 2
        temp_total = 0

        for elem in arr:
            if elem <= mid:
                temp_total += elem
            else :
                temp_total += mid

        if temp_total == total:
            answer = mid
            break
        elif temp_total < total:
            answer = max(mid, answer)
            start = mid + 1
        # 전체 예산을 넘기는 경우
        else :
            end = mid - 1

    # 계속 40번째 줄의 else문으로 빠져서 상한선이 0인 경우
    if answer == 0:
        answer = total // N

    print(answer)
