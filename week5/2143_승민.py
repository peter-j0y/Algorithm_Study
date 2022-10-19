import sys
input = sys.stdin.readline

T = int(input())
n = int(input())
arr1 = list(map(int, input().split()))
m = int(input())
arr2 = list(map(int, input().split()))

answer = 0

arr1_sum = [arr1[0]]
arr1_possible = arr1[:]
arr2_sum = [arr2[0]]
arr2_possible = arr2[:]

for i in range(1, len(arr1)) :
    sum = arr1[i] + arr1_sum[i-1]
    arr1_sum.append(sum)
    arr1_possible.append(sum)

if len(arr1_sum) >= 3:
    for i in range(3, len(arr1_sum) + 1):
        for j in range(i-2) :
            arr1_possible.append(arr1_sum[i-1] - arr1_sum[j])

for i in range(1, len(arr2)) :
    sum = arr2[i] + arr2_sum[i-1]
    arr2_sum.append(sum)
    arr2_possible.append(sum)

if len(arr2_sum) >= 3:
    for i in range(3, len(arr2_sum) + 1):
        for j in range(i-2) :
            arr2_possible.append(arr2_sum[i-1] - arr2_sum[j])

arr1_possible.sort()
arr2_possible.sort()

p1 = 0
p2 = len(arr2_possible) - 1
while p1 < len(arr1_possible) and p2 >= 0:
    sum = arr1_possible[p1] + arr2_possible[p2]
    if sum == T :
        arr1_value = arr1_possible[p1]
        arr2_value = arr2_possible[p2]
        temp_p1 = 0
        temp_p2 = 0

        while p1 < len(arr1_possible) and arr1_possible[p1] == arr1_value :
            temp_p1 += 1
            p1 += 1

        while p2 >= 0 and arr2_value == arr2_possible[p2] :
            temp_p2 += 1
            p2 -= 1
        
        answer += temp_p1 * temp_p2

    if sum < T :
        p1 += 1
    if sum > T :
        p2 -= 1

print(answer)
