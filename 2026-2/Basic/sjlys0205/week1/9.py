maxAns=0;
maxInd=0;

for i in range(1,10):
    a=int(input())
    if a>maxAns:
        maxAns=a
        maxInd=i

print(maxAns,maxInd,sep="\n")
