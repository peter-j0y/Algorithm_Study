import sys
input = sys.stdin.readline

variation_number = int(input())
expression = input().rstrip()
stack = []
dict = {}
for i in range(variation_number):
    dict[chr(ord('A')+i)] = int(input())

for value in expression:
    if value == '*' or value == '+' or value == '/' or value == '-' :
        term1 = stack.pop()
        term2 = stack.pop()
        if value == '*':
            stack.append(term2 * term1)
        elif value == '+':
            stack.append(term2 + term1)
        elif value == '-':
            stack.append(term2 - term1)
        else :
            stack.append(round(term2/term1, 2))

    else :
        stack.append(dict[value])

print(format(stack.pop(), ".2f"))