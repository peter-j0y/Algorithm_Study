import sys

input = sys.stdin.readline

n = int(input())

s = [] # 내구도 저장하는 배열
w = [] # 무게 저장하는 배열
isBroken = [False] * (n)
answer = 0

for _ in range(n):
    si, wi = map(int, input().split())
    s.append(si)
    w.append(wi)

def dfs(now, cnt): # now -> 현재 들고 있는 계란, cnt -> 부서진 계란 개수
    global answer

    if now == n or isBroken.count(True) == n-1:
        answer = max(answer, cnt)
        return
    
    if isBroken[now]:
        dfs(now+1, cnt)
        return
    
    for i in range(n):
        temp = 0

        if i == now:
            continue

        if isBroken[i] == False:
            s[now] -= w[i]
            s[i] -= w[now]

            if s[now] <= 0:
                isBroken[now] = True
                temp += 1
            if s[i] <= 0:
                isBroken[i] = True
                temp += 1

            dfs(now+1, cnt+temp)

            s[now] += w[i]
            s[i] += w[now]
            isBroken[now] = False
            isBroken[i] = False

dfs(0, 0)
print(answer)