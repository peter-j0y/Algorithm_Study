import sys

input = sys.stdin.readline

g = int(input())
answer = []

for i in range(1, int(g**(1/2))+1):
    if g % i == 0:
        a = i
        b = g // i
        if (a+b) % 2 == 0 and a-b != 0:
            x = (a+b)//2
            answer.append(x)

if not answer:
    print(-1)
else:
    answer.sort()
    print(*answer, sep='\n')