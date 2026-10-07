import sys


def solve():
    input=sys.stdin.readline
    n=int(input())
    
    stack=[]
    
    for i in range(n):
        cmd=input().split()
        op=cmd[0]
        
        if op=='push':
            stack.append(int(cmd[1]))
            
        elif op=='pop':
            if stack:
                print(stack.pop())
            else:
                print(-1)
                
        elif op=='size':
            print(len(stack))
    
        elif op=='empty':
            print(1 if not stack else 0)
   
        elif op=='top':
            if stack:
                print(stack[-1])
            else:
                print(-1)


if __name__=='__main__':
  solve()
