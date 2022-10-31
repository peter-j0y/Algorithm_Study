import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

T = int(input())

# 그리디 알고리즘 -> 점수를 정렬해서 순차적으로 거를 수 있지 않을까?
# 서류 점수를 기준으로 정렬 후 면접 점수가 앞의 사람보다 낮으면 탈락
# 통과!

def solution():
    scores = []
    n = int(input())
    for _ in range(n):
        p, i = map(int, input().split())
        scores.append([p, i])
    scores.sort(key = lambda x:x[0])
    newPerson = 1
    temp = scores[0][1]
    for idx, elem in enumerate(scores):
        if elem[1] < temp:
            temp = elem[1]
            newPerson += 1
    return newPerson

for _ in range(T):
    print(solution())
