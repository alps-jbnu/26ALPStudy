from collections import deque
import sys


def solve():
  input = sys.stdin.readline
  f, s, g, u, d = map(int, input().split())

  dist = [-1] * (f + 1)
  queue = deque([s])
  dist[s] = 0

  while queue:
    curr = queue.popleft()

    if curr == g:
      print(dist[curr])
      return

    next_up = curr + u
    if next_up <= f and dist[next_up] == -1:
      dist[next_up] = dist[curr] + 1
      queue.append(next_up)

    next_down = curr - d
    if next_down >= 1 and dist[next_down] == -1:
      dist[next_down] = dist[curr] + 1
      queue.append(next_down)

  print("use the stairs")


if __name__ == "__main__":
  solve()
