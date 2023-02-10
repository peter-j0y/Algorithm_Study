import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    
    answer = 0
    name = input().rstrip()

    min_move = len(name)

    for i, s in enumerate(name):
        answer += min(ord(s) - ord('A'), ord('Z') - ord(s) + 1)

        next = i + 1
        
        while next < len(name) and name[next] == 'A':
            next += 1

        min_move = min(min_move, 2*i+len(name)-next, 2*(len(name)-next)+i)

    answer += min_move

    print(answer)
