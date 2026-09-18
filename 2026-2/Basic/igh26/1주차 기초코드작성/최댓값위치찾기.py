a=[]
for i in range(9):
    n=int(input())
    a.append(n)
    
number=max(a)
index=a.index(number)+1

print(number)
print(index)
