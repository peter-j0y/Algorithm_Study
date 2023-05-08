import sys

input = sys.stdin.readline

v, e = map(int, input().split())
# 간선 정보를 저장하는 배열
edge_arr = []
answer = 0

for _ in range(e):
    a, b, c = map(int, input().split())
    edge_arr.append([a, b, c])

# 가중치 기준으로 정렬
edge_arr.sort(key=lambda x:x[2])

parent = [i for i in range(v+1)]

# 부모를 찾아가는 과정
def findParent(x):
    if parent[x] != x:
        parent[x] = findParent(parent[x])
    return parent[x]

for i in range(e):
    s, e, w = edge_arr[i]
    s_parent = findParent(s)
    e_parent = findParent(e)
    # 시작 노드의 부모와 끝 노드의 부모가 같으면 cycle이 존재하는 것
    if s_parent != e_parent:
        # 노드가 연결되기 때문에 부모를 갱신
        if s_parent < e_parent:
            parent[e_parent] = s_parent
        else:
            parent[s_parent] = e_parent
        answer += w

print(answer)