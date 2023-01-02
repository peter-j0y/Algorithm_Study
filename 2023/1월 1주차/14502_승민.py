import sys
import copy
from itertools import combinations
from collections import deque
sys.setrecursionlimit(10000)
input = sys.stdin.readline

# 풀이방법과 근거
# 바이러스가 퍼지지 않기 위한 가장 효율적인 정소에 벽을 세워야 함
# 벽을 세우기 위한 효율적인 방법이나 규칙을 발견하지 못함
# 벽을 반드시 3개 세워야 한다 + 시간제한 2초 + (3 ≤ N, M ≤ 8) 라는 조건을 통해
# 벽을 세우는 가능한 모든 경우의 수를 확인해가며 가장 효율적인 개수를 찾으면 될 것이라고 추측
# 벽을 세우는 모든 경우의 수를 조합으로 찾은 뒤 벽을 세우고 bfs를 수행하여 최댓값을 갱신하여 답을 구함

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def bfs(N, M, graph):
    global answer
    count = 0
    queue = deque()
    for i in range(N):
        for j in range(M):
            if graph[i][j] == 2:
                queue.append([i, j])
    
    while queue:
        y, x = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < M and 0 <= ny <N:
                if graph[ny][nx] == 0:
                    graph[ny][nx] = 2
                    queue.append([ny, nx])
    
    for i in range(N):
        count += graph[i].count(0)
    answer = max(answer, count)

N, M = map(int, input().split())

graph = [list(map(int, input().split())) for _ in range(N)]

zero_arr = []
answer = 0

for i in range(N):
    for j in range(M):
        if graph[i][j] == 0 :
            zero_arr.append([i, j])

combi_arr = list(combinations(zero_arr, 3))

for elem in combi_arr:
    graph_copy = copy.deepcopy(graph)
    for pos in elem:
        graph_copy[pos[0]][pos[1]] = 1
    bfs(N, M, graph_copy)

print(answer)
