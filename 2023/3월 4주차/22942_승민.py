import sys

input = sys.stdin.readline

n = int(input())
arr = []
stack = []

for idx in range(n):
    x, r = map(int, input().split())
    start = x - r
    end = x + r

    arr.append([start, idx, 0])
    arr.append([end, idx, 1])

arr.sort(key = lambda x: x[0])

for idx in range(n):

    if arr[idx][2] == 0:
        stack.append(arr[idx])
    
    else:
        if stack[-1][1] == arr[idx][1]:
            stack.pop()
        
        else :
            print('NO')
            exit()

print('YES')