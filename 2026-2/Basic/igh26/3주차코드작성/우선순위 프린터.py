from collections import deque
import sys


def solve():
  input = sys.stdin.readline
  t = int(input())

  for _ in range(t):
    n, m = map(int, input().split())
    priorities = list(map(int, input().split()))

    
    q = deque([(i, p) for i, p in enumerate(priorities)])
    print_order = 0

    while q:
      current = q.popleft()

      
      if any(current[1] < item[1] for item in q):
        q.append(current)  
      else:
        print_order += 1  
        if current[0] == m:  
          print(print_order)
          break


if __name__ == "__main__":
  solve()
