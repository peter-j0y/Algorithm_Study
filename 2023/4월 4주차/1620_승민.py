import sys

input = sys.stdin.readline

d_num_key = dict()
d_name_key = dict()

n, m = map(int, input().split())

for i in range(1,n+1):
    name = input().rstrip()
    d_num_key[i] = name
    d_name_key[name] = i

for _ in range(m):
    v = input().rstrip()
    """ 
    파이썬에서 제공하는 isdigit함수를 이용하면
    해당 문자열 안에 숫자가 포함되어 있는지 여부를 알 수 있다.
    문자가 단 하나라도 있다면 False를 반환하고
    모든 문자가 숫자로 이루어져 있다면 True를 반환한다.
    """
    if ord('A')<=ord(v[0])<=ord('Z') or ord('a')<=ord(v[0])<=ord('z'):
        print(d_name_key[v])
    else:
        print(d_num_key[int(v)])