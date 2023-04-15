import sys

input = sys.stdin.readline

n = int(input())

save_num = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

def dfs(cnt, now, arr): #cnt는 최종 자리수, now는 현재 자리수
    if now >= cnt:
        save_num.append(int(''.join(map(str, arr))))
        return
    
    if arr:
        last_num = arr[-1]
        no_more_small = True

        for i in range(last_num):
            no_more_small = False
            arr.append(i)
            dfs(cnt, now+1, arr)
            arr.pop()
        
        if no_more_small:
            return
    
for i in range(2, 11):
    for j in range(1, 10):
        dfs(i, 1, [j])

if n > len(save_num):
    print(-1)
else:
    print(save_num[n-1])