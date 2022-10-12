import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split(' ')))
flag = False

for i, elem in reversed(list(enumerate(arr))) :
    if i > 0 and arr[i] < arr[i-1] :
        ci = i - 1
        mi = 0
        temp = 0
        for j in range(i, n) :
            if arr[j] < arr[ci] and arr[j] > temp :
                mi = j
                temp = arr[j]
        arr[ci], arr[mi] = arr[mi], arr[ci]
        answer = arr[:i] + sorted(arr[i:], reverse=True)
        print(' '.join(map(str, answer)))
        flag = True
        break
if flag == False:
    print(-1)
