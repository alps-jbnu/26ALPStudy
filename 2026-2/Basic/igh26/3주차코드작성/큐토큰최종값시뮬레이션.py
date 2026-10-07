from collections import deque
import sys


def solve():
  n = int(sys.stdin.readline())


  q = deque(range(1, n + 1))

 
  while len(q) > 1:
    q.popleft()  
    q.append(q.popleft())  


  print(q[0])


if __name__ == "__main__":
  solve()
