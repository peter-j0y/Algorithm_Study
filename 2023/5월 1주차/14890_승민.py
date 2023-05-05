import sys

input = sys.stdin.readline

n, l = map(int, input().split())

answer = 0

graph = [list(map(int, input().split())) for _ in range(n)]

def check(line, l):
    slope = [False] * n
    now_idx = 0
    # 연속되는 정도, l과 비교하기 위함
    s = 1
    edge_idx = -1
    for i in range(1, n):
        # 경사로는 꿈도 못꾸는 경우
        if abs(line[now_idx] - line[i]) > 1:
            return False
        # 이전꺼랑 같은 경우
        elif line[now_idx] == line[i] and slope[i] == False:
            now_idx = i
            s += 1
        # 높이 차이가 1인 경우
        else:
            # 내리막 경사로
            if line[now_idx] > line[i]:
                edge_idx = i

                if edge_idx + l - 1 >= n:
                    return False
                for j in range(l):
                    if line[edge_idx+j] != line[edge_idx] or slope[edge_idx+j] == True:
                        return False
                    slope[edge_idx+j] = True

                now_idx += l
                s = 1

            # 오르막 경사로
            elif line[now_idx] < line[i]:
                edge_idx = now_idx
                if edge_idx - l + 1 < 0 or slope[edge_idx] == True:
                    return False
                if s>=l and edge_idx != -1:
                    for j in range(l):
                        if slope[edge_idx-j] == False:
                            slope[edge_idx-j] = True
                        else:
                            return False
                else:
                    return False
                now_idx = i
                s = 1
    return True

for i in range(n):
    if check(graph[i], l) == True:
        answer += 1

for i in range(n):
    arr = []
    for j in range(n):
        arr.append(graph[j][i])
    if check(arr, l) == True:
        answer += 1

print(answer)