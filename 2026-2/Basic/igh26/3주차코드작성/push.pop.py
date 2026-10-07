import sys

input=sys.stdin.readline

n=int(input())
stack=[]
result=[]
current=1
possible=True

for _ in range(n):
    target=int(input())
    
    while current<=target:
        stack.append(current)
        result.append('+')
        current+=1
    if stack[-1]==target:
        stack.pop()
        result.append('-')
    else:
        possible=False
        break

if not possible:
  print('NO')
else:
  print('\n'.join(result))
