import sys

input = sys.stdin.readline

n, m = map(int, input().split())

arr = list(map(int, input().split()))

# 최소 블루레이 크기
left = max(arr)
# 최대 블루레이 크기
right = sum(arr)

while left <= right:
    mid = (left + right) // 2
    # 현재 1개의 블루레이에 누적된 크기
    s = 0
    # 블루레이 개수
    cnt = 1
    
    for i in range(n):
        if arr[i] + s >mid:
            cnt += 1
            s = 0
        
        s += arr[i]
    
    if cnt > m:
        left = mid + 1
    
    elif cnt <= m:
        right = mid - 1

print(left)