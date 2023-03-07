import sys

input = sys.stdin.readline

# n = 100,000 m = 100,000
# n * m = 10,000,000,000
n, m = map(int, input().split())

arr = []
segmentTree = [0] * (4*n)

def makeSegTree(idx, start, end):
    # 리프노드인 경우
    if start == end:
        segmentTree[idx] = (arr[start], arr[end])
        return segmentTree[idx]
    
    # 리프노드가 아닌 경우
    mid = (start + end)//2
    left = makeSegTree(idx*2, start, mid)
    right = makeSegTree(idx*2+1, mid+1, end)

    segmentTree[idx] = (min(left[0], right[0]), max(left[1], right[1]))
    return segmentTree[idx]


# idx는 트리의 인덱스, start, end 현재 노드의 범위, left, right 찾고자 하는 배열의 범위
def solution(idx, start, end, left, right):

    # left와 right가 트리의 범위를 벗어난 경우
    if right < start or left > end:
        return (10**9, 0)
    
    if left <= start and end <= right:
        return segmentTree[idx]
    
    mid = (start + end)//2
    left_child = solution(idx*2, start, mid, left, right)
    right_child = solution(2*idx+1, mid+1, end, left, right)
    return(min(left_child[0], right_child[0]), max(left_child[1], right_child[1]))    
    
    
for _ in range(n):
    arr.append(int(input()))

makeSegTree(1, 0, len(arr)-1)

for _ in range(m):
    a, b = map(int, input().split())

    ans = solution(1, 0, n-1, a-1, b-1)
    print(ans[0], ans[1])
    