import math

def solution(brown, yellow):
    answer = []
    for i in range(1, int(math.sqrt(yellow)) + 1):
        if yellow % i == 0:
            width = yellow // i
            height = i
        temp_brown = (width + 2) * (height + 2) - yellow
        if temp_brown == brown:
            answer.append(width + 2)
            answer.append(height + 2)
            break

    return answer