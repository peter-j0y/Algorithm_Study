import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

N = int(input())
arr = []
dict = {}

for i in range(N):
    arr.append(input().strip())

for word in arr:
    # w_len은 제곱수, 즉 단어가 3글자면 100자리수이므로 -1을 해준 10의 2 제곱을 곱해야 3자리가 됨
    w_len = len(word) - 1
    for i in range(len(word)):
        # 만약 딕셔너리에 있으면
        if word[i] in dict:
            dict[word[i]] += pow(10, w_len)
        # 딕셔너리에 없으면
        else :
            dict[word[i]] = pow(10, w_len)
        # 제곱수 1씩 감소
        w_len -= 1

# 딕셔너리 값으로 내림차순 정렬
sorted_dict = sorted(dict.items(), key = lambda item: item[1], reverse = True)

# 값이 가장 많은 순서이므로 9부터 대입
result, num = 0, 9
for elem in sorted_dict:
    result += elem[1] * num
    num -= 1

print(result)
