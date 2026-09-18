import sys

cnt=int(input())
ans=[]

for i in range(cnt):
    a,b = map(int,sys.stdin.readline().split())
    ans.append(str(a+b))

sys.stdout.write('\n'.join(ans) + '\n')
