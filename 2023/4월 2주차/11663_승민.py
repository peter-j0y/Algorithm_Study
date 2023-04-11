import sys
input = sys.stdin.readline

n, m = map(int, input().split())

dots = list(map(int, input().split()))
dots.sort()

def binary_search(dest):
    st = 0
    ed = n-1

    while st<=ed:
        mid = (st+ed)//2

        if dots[mid] == dest:
            return mid

        if dots[mid] < dest:
            st = mid+1
        else:
            ed = mid-1
    
    return mid

for _ in range(m):
    st, ed = map(int, input().split())
    st_idx = binary_search(st)
    ed_idx = binary_search(ed)

    if dots[st_idx] < st:
        st_idx += 1
    if dots[ed_idx] > ed:
        ed_idx -= 1
    
    answer = ed_idx - st_idx + 1
    
    print(answer)