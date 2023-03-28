import sys
sys.setrecursionlimit(int(1e9))

input = sys.stdin.readline

n = list(input().rstrip())

dp = [[0] * (len(n)-1) for i in range(1,len(n)-1)]

min_res = int(1e9)
max_res = 0

def sol(arr, cnt):
    temp = 0
    global min_res
    global max_res

    if len(arr) == 1:
        if int(arr[0]) % 2 == 1:
            temp += 1
        min_res = min(cnt + temp, min_res)
        max_res = max(cnt + temp, max_res)
        return
    
    if len(arr) == 2:
        if int(arr[0]) % 2 == 1:
            temp += 1

        if int(arr[1]) % 2 == 1:
            temp += 1
        
        arr = list(str(int(arr[0]) + int(arr[1])))
        sol(arr, cnt + temp)
    
    if len(arr) >= 3:
        for elem in arr:
            if int(elem) % 2 == 1:
                temp += 1

        for i in range(1, len(arr)-1):
            for j in range(i+1, len(arr)):
                new_arr = list(str(int("".join(s for s in arr[:i])) + int("".join(s for s in arr[i:j])) + int("".join(s for s in arr[j:]))))
                sol(new_arr, cnt + temp)

sol(n, 0)

print(min_res, max_res)