a,b=map(int,input().split())

if a<b:
    betNum=b-a-1
else:
    betNum=a-b-1

if betNum==0 or betNum==-1:
    print(0)
else:
    print(betNum)
    if a<b:
        for i in range(a+1,b):
            print(i,end=" ")
    else:
        for i in range(b+1,a):
            print(i,end=" ")
