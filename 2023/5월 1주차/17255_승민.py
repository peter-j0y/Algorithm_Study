import sys
sys.setrecursionlimit(int(1e5))

input = sys.stdin.readline

n = input().rstrip()

answer = 0

def dfs(string):
    global answer
    set_string = set(list(string))

    # 겹치는 숫자는 set으로 제거
    if len(set_string) == 1:
        answer += 1
        return
    
    # 맨 앞의 숫자 제거
    dfs(string[1:])
    # 맨 뒤의 숫자 제거
    dfs(string[:-1])

dfs(n)
print(answer)