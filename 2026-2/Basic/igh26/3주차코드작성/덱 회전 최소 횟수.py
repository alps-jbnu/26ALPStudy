from collections import deque
import sys

n,m=map(int, sys.stdin.readline().split())
targets=list(map(int, sys.stdin.readline().split()))

dq=deque(range(1, n + 1))
total_rotations=0

for target in targets:
    idx=dq.index(target)
    
    if idx<=len(dq)//2:
        total_rotations+=idx
        dq.rotate(-idx)
    else:
        total_rotations+=len(dq)-idx
        dq.rotate(len(dq)-idx)  
  
    dq.popleft()

print(total_rotations)
