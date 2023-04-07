import sys
from itertools import combinations

input = sys.stdin.readline

n, m = map(int, input().split())

guitars = set()
max_cnt = 0
answer = 0

for _ in range(n):
    binary_str = ''
    name, songs = input().rstrip().split()

    for elem in songs:
        if elem == 'Y':
            binary_str += '1'
        elif elem == 'N':
            binary_str += '0'
    
    guitars.add(int(binary_str, 2))

guitars -= {0}
if not guitars:
    print(-1)
    exit()

for i in range(1, n+1):
    for combs in combinations(guitars, i):
        temp = 0
        for num in combs:
            temp |= num
        
        temp_cnt = 0
        for j in range(m):
            if temp & (1 << j):
                temp_cnt += 1  

        if max_cnt < temp_cnt:
            max_cnt = temp_cnt
            answer = i

print(answer)
