import sys
sys.setrecursionlimit(int(1e9))

def usage2Charge(usage):
    charge = 0
    if usage <= 100:
        return usage * 2

    charge += 200
    usage -= 100

    if usage <= 9900:
        return charge + usage * 3

    charge += 9900 * 3
    usage -= 9900

    if usage <= 990000:
        return charge + usage * 5

    charge += 990000 * 5
    usage -= 990000

    return charge + usage * 7


def charge2Usage(charge):
    usage = 0

    if charge <= 200:
        return charge // 2

    charge -= 200
    usage += 100

    if charge <= 3 * 9900:
        return usage + charge // 3

    charge -= 3 * 9900
    usage += 9900

    if charge <= 5 * 990000:
        return usage + charge // 5

    charge -= 5 * 990000
    usage += 990000

    return usage + charge // 7

def binarySearch(s, e, total, target):
    mid = (s + e) // 2
    ch1 = usage2Charge(mid)
    ch2 = usage2Charge(total-mid)

    if abs(ch1 - ch2) == target:
        print(min(ch1, ch2))
        return
    elif abs(ch1 - ch2) < target:
        binarySearch(mid, e,total, target)
    else:
        binarySearch(s, mid,total, target)

input = sys.stdin.readline


while True:
    a, b = map(int, input().split())

    if a == 0 and b == 0: break

    total = charge2Usage(a)
    binarySearch(0, total, total, b)

