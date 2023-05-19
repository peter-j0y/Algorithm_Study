import sys

input = sys.stdin.readline

def getPrice(elec):
    if elec <= 100:
        return elec*2
    elif elec <= 10000:
        return 100*2 + (elec-100)*3
    elif elec <= 1000000:
        return 100*2 + 9900*3 + (elec-10000)*5
    else:
        return 100*2 + 9900*3 + 990000*5 + (elec-1000000)*7

while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break

# total_elec는 나와 이웃의 전력량의 합
    if a <= 100*2:
        total_elec = a // 2
    elif a <= 9900*3 + 100*2:
        a -= 100*2
        total_elec = 100
        total_elec += a // 3
    elif a <= 990000*5 + 9900*3 + 100*2:
        a -= (100*2 + 9900*3)
        total_elec = 10000
        total_elec += a // 5
    else:
        a -= (100*2 + 9900*3 + 990000*5)
        total_elec = 1000000
        total_elec += a // 7
    
    st = 0
    ed = total_elec
    # mid는 상근이의 전력 사용량
    while st <= ed:
        mid = (st+ed)//2
        neighbor_elec = total_elec - mid
        sanggeun_price = getPrice(mid)
        neighbor_price = getPrice(neighbor_elec)
        diff = abs(sanggeun_price-neighbor_price)
        if diff == b:
            break
        elif diff < b:
            ed = mid-1
        else:
            st = mid+1
    print(sanggeun_price)