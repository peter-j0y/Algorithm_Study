import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

# 문제를 처음 보고 든 생각
# 가장 많은 사람들의 치킨거리에 해당하는 가게를 없애면 안되겠다..?
# 근데 거리가 극단적이면 사람 수와 비례 안하는 경우가 생김
# 치킨집 좌표를 배열에 저장한 다음에 M개만 뽑고 나머지는 없애고 최솟값 구하기?
# 시간초과 나지 않을까? 제한 시간 1초 
# 이거 왜 시간초과 안나지..? 40개 중에 13개만 조합해도 120억인데..?
# 아 치킨집 개수가 M보다 크거나 13보다 작거나 같구나..ㅋㅋ

N, M = map(int, input().split())

graph = [list(map(int, input().split())) for _ in range(N)]
chickens = []
houses = []

for i in range(N):
    for j in range(N):
        if graph[i][j] == 1:
            houses.append([i, j])
        if graph[i][j] == 2:
            chickens.append([i, j])

def comb(chickens, M) :
    result = []
    if M == 0:
        return [[]]

    for i in range(len(chickens)):
        elem = chickens[i]
        for j in comb(chickens[i+1:], M-1):
            result.append([elem] + j)
    return result

comb_result = comb(chickens, M)
answer = 10e9
for elem in comb_result:
    temp = 0
    for house in houses:
        chicken_dist = 10e9
        for chicken in elem:
            chicken_dist = min(chicken_dist, abs(chicken[0]-house[0]) + abs(chicken[1]-house[1]))
        temp += chicken_dist
    answer = min(answer, temp)

print(answer)
