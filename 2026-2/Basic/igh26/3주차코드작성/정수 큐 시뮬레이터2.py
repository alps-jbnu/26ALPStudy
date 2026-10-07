from collections import deque
import sys


def solve():
  input = sys.stdin.readline
  n = int(input())
  q = deque()

  for _ in range(n):
    command = input().split()
    cmd = command[0]

    if cmd == 'push':
      q.append(int(command[1]))
    elif cmd == 'pop':
      if q:
        print(q.popleft())
      else:
        print(-1)
    elif cmd == 'size':
      print(len(q))
    elif cmd == 'empty':
      print(1 if not q else 0)
    elif cmd == 'front':
      if q:
        print(q[0])
      else:
        print(-1)
    elif cmd == 'back':
      if q:
        print(q[-1])
      else:
        print(-1)


if __name__ == '__main__':
  solve()
