import sys
import heapq

sys.setrecursionlimit(10000)
input = sys.stdin.readline

def check(x, y, cx, cy, r):
    if (x-cx)**2 + (y-cy)**2 < r**2:
        return True
    return False

t = int(input())

for _ in range(t):
    x1, y1, x2, y2 = map(int, input().split())
    n = int(input())
    answer = 0

    for _ in range(n):
        cx, cy, r = map(int, input().split())
        if check(x1, y1, cx, cy, r):
            answer += 1
        if check(x2, y2, cx, cy, r):
            answer += 1
        if check(x1, y1, cx, cy, r) and check(x2, y2, cx, cy, r):
            answer -= 2

    print(answer)
