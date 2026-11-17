from collections import deque
import sys


def solve():
  input = sys.stdin.readline
  n = int(input())
  grid = [list(map(int, input().strip())) for _ in range(n)]
  visited = [[False] * n for _ in range(n)]

  dx = [-1, 1, 0, 0]
  dy = [0, 0, -1, 1]

  cluster_sizes = []

  for i in range(n):
    for j in range(n):
      if grid[i][j] == 1 and not visited[i][j]:
        queue = deque([(i, j)])
        visited[i][j] = True
        size = 1

        while queue:
          x, y = queue.popleft()
          for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]

            if 0 <= nx < n and 0 <= ny < n:
              if grid[nx][ny] == 1 and not visited[nx][ny]:
                visited[nx][ny] = True
                queue.append((nx, ny))
                size += 1

        cluster_sizes.append(size)
  cluster_sizes.sort()
  print(len(cluster_sizes))
  for size in cluster_sizes:
    print(size)


if __name__ == "__main__":
  solve()
