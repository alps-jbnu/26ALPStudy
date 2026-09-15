a=[]
for i in range(7):
  n=int(input())
  if n%2 !=0:
    a.append(n)

if not a:
  print(-1)
else:
  print(sum(a))
  print(min(a))
