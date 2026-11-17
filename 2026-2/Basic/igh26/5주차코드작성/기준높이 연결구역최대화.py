from collections import deque
import sys


def solve():
  input = sys.stdin.readline
  n = int(input())
  grid = [list(map(int, input().split())) for _ in range(n)]
  max_height = max(max(row) for row in grid)
  max_components = 0

  dx = [-1, 1, 0, 0]
  dy = [0, 0, -1, 1]

  for h in range(max_height + 1):
    visited = [[False] * n for _ in range(n)]
    current_components = 0

    for i in range(n):
      for j in range(n):
        if grid[i][j] > h and not visited[i][j]:
          queue = deque([(i, j)])
          visited[i][j] = True
          current_components += 1

          while queue:
            x, y = queue.popleft()
            for d in range(4):
              nx = x + dx[d]
              ny = y + dy[d]

              if 0 <= nx < n and 0 <= ny < n:
                if grid[nx][ny] > h and not visited[nx][ny]:
                  visited[nx][ny] = True
                  queue.append((nx, ny))

    if current_components > max_components:
      max_components = current_components

  print(max_components)


if __name__ == "__main__":
  solve()
