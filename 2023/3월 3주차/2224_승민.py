import sys
import heapq

input = sys.stdin.readline

INF = int(1e9)
al = 30
graph = [[False] * (al*2) for _ in range(al*2)]
cnt = 0

n = int(input())

for _ in range(n):
    s = list(input().rstrip())
    st = ord(s[0]) - ord('A')
    end = ord(s[-1]) - ord('A')
    if st != end:
        graph[st][end] = True

for i in range(al*2):
    for j in range(al*2):
        for k in range(al*2):
            if graph[j][k] == False and (graph[j][i] == True and graph[i][k] == True):
                graph[j][k] = True

for i in range(al*2):
    for j in range(al*2):
        if i != j and graph[i][j] == True:
            cnt += 1

print(cnt)

for i in range(al*2):
    for j in range(al*2):
        if i != j and graph[i][j] == True:
            print(chr(i+ord('A')), "=>", chr(j+ord('A')))