import sys

input = sys.stdin.readline
    
n = int(input())
arr = [0]
same_arr = []
max_cnt = 0
answer = set()

for _ in range(n):
    arr.append(int(input()))

def dfs(now):
    if visited[now] == True:
        return
    visited[now] = True
    f_set.add(now)
    s_set.add(arr[now])
    dfs(arr[now])

for i in range(1, n+1):
    visited = [False]*(n+1)
    f_set = set()
    s_set = set()
    dfs(i)

    if f_set == s_set:
        # 별개의 순환되는 그룹이 존재하는 경우
        # 반례 2 3 2 5 6 5
        if len(answer & f_set) == 0:
            max_cnt += len(f_set)
            answer = answer | f_set

        # 하나의 순환 그룹이지만 개수가 많은 것을 선택해야 하는 경우
        elif len(f_set) > max_cnt:
            max_cnt = len(f_set)
            answer = list(f_set)

answer = list(answer)
answer += same_arr
max_cnt += len(same_arr)

answer.sort()
print(max_cnt)
for elem in answer:
    print(elem)