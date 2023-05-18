import sys
sys.setrecursionlimit(int(1e9))

input = sys.stdin.readline

n, m = map(int, input().split())
arr = []
for i in range(n+1):
    arr.append(i)

def find_parent(x):
    if x != arr[x]:
        arr[x] = find_parent(arr[x])
    return arr[x]

def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a > b:
        arr[a] = b
    else:
        arr[b] = a

# {0}, {1}, {2}, {3} ... 
for _ in range(m):
    type, a, b = map(int, input().split())
    p_a = find_parent(a)
    p_b = find_parent(b)
    if type == 1:
        if p_a == p_b:
            print("yes")
        else:
            print("no")
    elif type == 0 and p_a != p_b:
        union_parent(a, b)