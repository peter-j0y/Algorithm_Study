import sys, heapq
sys.setrecursionlimit(10000)
input = sys.stdin.readline

# 처음 든 생각
# 그리디 알고리즘 -> 정렬을 해보자 -> 앞에 있을 수록 묶음에 포함되는 횟수가 증가
# 8%에서 틀렸습니다..
# N이 1인 경우는 그냥 해당 카드 묶음 자체인가?
# 카드 묶음을 비교하는 횟수이므로 N이 1이면 비교할 카드 묶음이 없기 때문에 0일 것이다.
# 알고리즘 분류를 봄 -> 자료 구조, 그리디 알고리즘, 우선순위 큐
# 어 그냥 배열을 정렬해서 풀어서 틀렸다고 하는건가..? heap을 써보자!
# 질문 검색 -> 정렬해서 순차적으로 합치는게 최선이 아님, 합치는 시점을 기준으로 가장 작은 뭉치를 합쳐야함
# 예를 들어 10, 20, 25, 27이 있으면 10과 20을 합치면 30인데 30과 25를 합치는게 아니라 25와 27을 합쳐야함.
# 통과~

N = int(input())

cards = []
for _ in range(N):
    heapq.heappush(cards, int(input()))

answer = 0
if N > 1:
    while len(cards)>1:
        temp = heapq.heappop(cards) + heapq.heappop(cards)
        answer += temp
        heapq.heappush(cards, temp)

print(answer)
