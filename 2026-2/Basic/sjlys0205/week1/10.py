num=list(map(int,input().split()))

for i in range(3):
    a=min(num)
    num.remove(a)
    print(a,end=" ")
