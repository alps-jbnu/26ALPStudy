def grade(stick):
    if (stick.count(1)==4):
        print("E")
    elif (stick.count(1)==3):
        print("A")
    elif (stick.count(1)==2):
        print("B")
    elif (stick.count(1)==1):
        print("C")
    elif (stick.count(1)==0):
        print("D")


stick_a=list(map(int,input().split()))
stick_b=list(map(int,input().split()))
stick_c=list(map(int,input().split()))

grade(stick_a)
grade(stick_b)
grade(stick_c)
