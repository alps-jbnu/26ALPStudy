import sys
n=int(sys.stdin.readline())

for i in range(n):
    s1,s2=sys.stdin.readline().split()
    
    if sorted(s1)==sorted(s2):
        print("Possible")
    else:
        print("Impossible")
