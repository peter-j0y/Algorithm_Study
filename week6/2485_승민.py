import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

# 문제를 처음 보고 든 생각
# 모두 간격이 같아야되니까 일단 간격의 값들을 구한뒤
# 가장 작은 간격을 유지하면 그게 최소 가로수의 개수 아닌가?
# 그러면 간격 사이의 최대 공약수를 구하면 가로수의 개수가 나오지 않을까?

def gcd(x, y):
    while y != 0:
        x, y = y, x % y
    return x

n = int(input())
trees = []
interval = []
for i in range(n):
    trees.append(int(input()))

for i in range(1, len(trees)):
    interval.append(trees[i]-trees[i-1])

gcdTemp = interval[0]
for i in range(1, len(interval)):
    gcdTemp = gcd(gcdTemp, interval[i])

gap = trees[-1] - trees[0]
treeCount = gap // gcdTemp + 1
print(treeCount-len(trees))
