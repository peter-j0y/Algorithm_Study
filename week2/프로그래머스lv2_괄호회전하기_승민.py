def checkCorrectString(s):
    stack = []
    for elem in s:
        if elem == '[' or elem == '(' or elem == '{':
            stack.append(elem)
        else :
            if stack :
                if elem == ')' and stack[-1] == '(':
                    stack.pop()
                if elem == ']' and stack[-1] == '[':
                    stack.pop()
                if elem == '}' and stack[-1] == '{':
                    stack.pop()
            else :
                return False
    if stack:
        return False
    return True

def solution(s):
    answer = 0
    length = len(s)
    for _ in range(length):
        if checkCorrectString(s):
            answer += 1
        s = s[1:] + s[0]
            
    return answer