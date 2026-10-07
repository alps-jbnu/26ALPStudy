N = int(input())
A = input()
g = list(map(int, A.split()))
arr = [0] * N

for i in range(1,N):
    for a in range(i-1,-1,-1):
        if g[a]>=g[i] :
            arr[i]=a+1
            break

print(*arr)
