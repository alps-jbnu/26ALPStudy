add_ans=0
min_ans=0

for i in range(7):
    a=int(input())
    if a%2==1:
        add_ans+=a
        if min_ans==0:
            min_ans=a
        elif min_ans>a:
            min_ans=a

if add_ans==0:
    print(-1)
else:
    print(add_ans)
    print(min_ans)
