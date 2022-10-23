import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

# 문제를 처음보고 든 생각
# 간선의 크기를 저장해야 하므로 이차원 배열을 이용해 트리의 정보를 저장(graph 변수에 해당), 방문 여부를 판단하기 위한 visited 배열 추가
# 트리의 지름을 구하기 위해서는 한 노드를 중심으로 잡고 dfs를 하면 되지 않을까? 변수 하나에 지름을 저장해서 큰 값이 나오면 갱신
# 모든 노드마다 지름을 구해서 가장 큰 값을 출력하면 되지 않나?
# 1차 시도
# 메모리 초과 -> 메모리를 어디서 줄여야 할까? visited 배열을 매 노드를 반복할 때마다 만들어서 메모리를 많이 만들어서인가?
# 근데 지름의 최대를 구하는거면 노드가 하나만 연결되어 있는 노드가 무조건 지름의 끝이어야하지 않나?
# 2차 시도
# 노드 하나만 연결된 경우만 계산해도 메모리 초과가 남 -> visited 배열 부분 수정 예정 및 모든 노드 입력이 번호순으로 들어오는게 아님
# 3차 시도
# 모든 경우를 다 순회할 필요가 없음 -> 아무 한 노드를 잡고 가장 먼 노드를 구함. 가장 먼 노드를 기준으로 다시 가장 먼 노드를 구하면 그게 지름임
# 4차 시도
# 메모리 초과 문제는 graph를 (v+1)*(v+1)로 만들어서 생긴 불필요한 메모리 차지라고 생각해서 수정
# 통과!

v = int(input())
graph = [[] for _ in range(v+1)]
answer = 0

for i in range(v):
    arr = list(map(int, input().split()))
    for idx, elem in enumerate(arr):
        if elem == -1 :
            break
        if idx == 0 :
            continue
        if idx % 2 == 1:
            graph[arr[0]].append([arr[idx], arr[idx+1]])

secondNode = 0

def dfs(now, temp):
    visited[now] = True
    global answer
    global secondNode
    if temp > answer:
        secondNode = now
        answer = temp
    for j in range(0, len(graph[now])):
        if visited[graph[now][j][0]] == False:
            dfs(graph[now][j][0], temp + graph[now][j][1])

visited = [False] * (v+1)
dfs(1, 0)
s = secondNode
visited = [False] * (v+1)
dfs(s, 0)

print(answer)
