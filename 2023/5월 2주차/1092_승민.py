import sys

input = sys.stdin.readline

n = int(input())
cranes = list(map(int, input().split()))
m = int(input())
boxes = list(map(int, input().split()))

moved = [False] * m
cranes.sort(reverse=True)
boxes.sort(reverse=True)

if cranes[0] < boxes[0]:
    print(-1)
    exit()

answer = 0
moved_count = 0
while moved_count != m:
    st_crane = 0
    st_box = 0
    while st_crane < n and st_box < m:
        # 만약 크레인이 감당할 수 있는 무게가 박스보다 크고 아직 옮겨지지 않았다면
        if cranes[st_crane] >= boxes[st_box] and not moved[st_box]:
            moved[st_box] = True
            moved_count += 1
            st_box += 1
            st_crane += 1
        # 이미 옮겨진 박스거나 크레인이 감당할 수 없는 경우라면 다음 박스 체크
        else:
            st_box += 1
    answer += 1
    
print(answer)
