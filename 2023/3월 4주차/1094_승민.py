import sys

input = sys.stdin.readline

arr = [64]

x = int(input())

ans = 0

while sum(arr) != x:
    

    if sum(arr) > x:
        arr[-1] //= 2

        if sum(arr) < x:
            arr.append(arr[-1])

print(len(arr))