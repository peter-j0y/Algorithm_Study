import sys
import heapq

input = sys.stdin.readline

n = int(input())
times = []

for _ in range(n):
    idx, st, ed = map(int, input().split())
    times.append([st, ed])

times.sort(key=lambda x: x[0])
rooms = [0]
# 100,000
for elem in times:
    st = elem[0]
    ed = elem[1]

    fastest = heapq.heappop(rooms)
    if fastest > st:
        heapq.heappush(rooms, fastest)
    heapq.heappush(rooms, ed)

print(len(rooms))