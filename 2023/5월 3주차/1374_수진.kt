import heapq

n = int(input())
lectures = list()
answer = 0

for i in range(0, n):
    lectures.append(list(map(int, input().split())))

lectures.sort(key = lambda x: x[1])

heap = []

for l in lectures:
    while heap and heap[0] <= l[1]:
        heapq.heappop(heap)
    heapq.heappush(heap, l[2])
    answer = max(answer, len(heap))

print(answer)

