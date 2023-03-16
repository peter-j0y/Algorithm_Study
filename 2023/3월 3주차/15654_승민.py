import sys

input = sys.stdin.readline

n, m = map(int, input().split())

arr = list(map(int, input().split()))

arr.sort()
q = []
visited = [False] * n

# 함수의 인자에 배열의 길이를 넘겨줌
def dfs(l):
    # 만약 배열의 길이가 m과 같다면 출력
    if l == m:
        print(' '.join(map(str, q)))
        return
    
    # 아직 배열의 길이가 적으면
    for i in range(n):
        # 방문하지 않은 원소를 큐에 넣고 dfs 재귀 돌림
        if visited[i] == False:
            q.append(arr[i])
            visited[i] = True
            dfs(l + 1)
            # 백트래킹으로 상태 원상복귀
            visited[i] = False
            q.pop()

dfs(0)