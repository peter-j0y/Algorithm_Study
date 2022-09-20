import math
import sys
input = sys.stdin.readline

def isPrime(num):
    for i in range(2, int(math.sqrt(num))+1):
        if num%i == 0:
            return False
    return True

def findNum(num):
    for i in range(2, num//2 + 1):
        if isPrime(i) and i % 2 == 1 and isPrime(num - i) and (num - i) % 2 == 1:
            return i
    return -1

while(True):
    num = int(input())
    if num == 0 :
        break
    result = findNum(num)
    if result == -1:
        print("Goldbach's conjecture is wrong.")
    else:
        print(str(num) + " = " + str(result) + " + " + str(num-result))