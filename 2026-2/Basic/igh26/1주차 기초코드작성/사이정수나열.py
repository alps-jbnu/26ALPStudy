a,b=map(int,input().split())
n=min(a,b)
m=max(a,b)
number=list(range(n+1,m))
print(len(number))
if number:
  print(*number)
