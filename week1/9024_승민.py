import sys
input = sys.stdin.readline

def solution():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    start = 0
    end = len(arr) - 1
    close_num = arr[start] + arr[end]
    count = 0
    while start < end :
        temp = arr[start] + arr[end]
        if abs(temp - k) == abs(close_num - k) :
            count += 1
        elif abs(temp - k) < abs(close_num - k) :
            close_num = temp
            count = 1
        
        if temp < k :
            start += 1
        else :
            end -= 1
    return count

tc = int(input())
for _ in range(tc):
    print(solution())