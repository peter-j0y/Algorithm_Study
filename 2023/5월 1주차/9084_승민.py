import sys

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    c = int(input())

    # dp[i]는 i원을 만드는 방법의 수
    #    0 1 2 3 4 5 6 7 8 9 10
    # 2  1 0 1 0 1 0 1 0 1 0 1
    # 3  1 0 1 1 1 1 2 1 1 2 1
    # 5  1 0 1 1 1 2 2 2 3 3 4
    # 동전의 입력이 오름차순으로 입력받음을 이용하여 동전 종류를 순회하면서 dp를 갱신
    dp = [0] * (c+1)
    dp[0] = 1

    for elem in arr:
        for i in range(c+1):
            if i >= elem:
                dp[i] += dp[i-elem]
    
    print(dp[c])