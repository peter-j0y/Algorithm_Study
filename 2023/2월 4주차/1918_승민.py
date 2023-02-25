import sys

sys.setrecursionlimit(10000)
input = sys.stdin.readline

exp = input()
stack = []
answer = ""

flag = False

for idx, char in enumerate(exp):
    if flag == True:
        flag = False
        continue

    if char == '+' or char == '-':
        
        while stack:
            peek = stack[-1]
            if peek == '+' or peek == '-':
                answer += stack.pop()
            else:
                break

    if ord('A') <= ord(char) and ord(char) <= ord('Z'):
        answer += char
    
    elif char == '(' or char == '+' or char == '-':
        stack.append(char)
    
    elif char == '*' or char == '/':
        if exp[idx+1] != '(':
            answer += exp[idx+1]
            answer += char
            flag = True
        
        else:
            stack.append(char)

    elif char == ')':
        while stack:
            peek = stack.pop()
            if peek == '(':
                break
            elif peek != '(' and peek != ')':
                answer += peek
        
        if stack:
            peek = stack[-1]
            if peek == '*' or peek == '/':
                answer += stack.pop()

            elif peek == '+' or peek == '-':
                if idx + 1 < len(exp):
                    if exp[idx+1] != '*' and exp[idx+1] != '/':
                        answer += stack.pop()
    
while stack:
    peek = stack[-1]
    if peek != '(' or peek != ')':
        answer += stack.pop()

print(answer)
