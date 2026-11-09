from collections import deque
import sys


def solve():
  input = sys.stdin.readline
  n, m = map(int, input().split())
  grid = [list(map(int, input().strip())) for _ in range(n)]
  visited = [[[0] * 2 for _ in range(m)] for _ in range(n)]

  queue = deque([(0, 0, 0)])  
  visited[0][0][0] = 1

  dx = [-1, 1, 0, 0]
  dy = [0, 0, -1, 1]

  while queue:
    x, y, broken = queue.popleft()
    if x == n - 1 and y == m - 1:
      print(visited[x][y][broken])
      return

    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]

      if 0 <= nx < n and 0 <= ny < m:
        if grid[nx][ny] == 0 and visited[nx][ny][broken] == 0:
          visited[nx][ny][broken] = visited[x][y][broken] + 1
          queue.append((nx, ny, broken))
        elif grid[nx][ny] == 1 and broken == 0 and visited[nx][ny][1] == 0:
          visited[nx][ny][1] = visited[x][y][0] + 1
          queue.append((nx, ny, 1))
  print(-1)


if __name__ == "__main__":
  solve()
