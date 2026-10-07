import sys


def solve():
    input=sys.stdin.readline
    n=int(input())
    heights=list(map(int, input().split()))
    
    stack=[]
    result=[]
    
    for i in range(n):
        h=heights[i]
        current_index=i+1 
        
        while stack and stack[-1][1]<=h:
            stack.pop()
            
        if not stack:
            result.append(0)
            
        else:
            result.append(stack[-1][0])
            
        stack.append((current_index, h))

    print(*result)


if __name__=="__main__":
  solve()
