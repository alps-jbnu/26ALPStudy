chk=int(input())

if ((chk%4==0 and chk%100!=0) or chk%400==0):
    print(1)
else:
    print(0)
