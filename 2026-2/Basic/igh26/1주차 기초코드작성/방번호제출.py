r=input()
list=[0,0,0,0,0,0,0,0,0,0]

for i in r:
    num=int(i)
    if num==6 or num==9:
        list[6]+=1
    else:
        list[num]+=1
import math
list[6]=math.ceil(list[6]/2)
print(max(list))
