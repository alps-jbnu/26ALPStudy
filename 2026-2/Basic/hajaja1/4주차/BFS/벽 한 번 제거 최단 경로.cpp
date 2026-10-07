#include <bits/stdc++.h>
using namespace std;
string board[1005];
int vis[1005][1005][2];
int N, M;

int dx[4] = { 1, 0 ,-1, 0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	// 예외 처리: 시작점과 도착점이 같은 경우
	if (N == 1 && M == 1) {
		cout << 1;
		return 0;
	}

	queue<tuple<int, int, int>> Q; // {x(행), y(열), 벽 부수기 여부}
	Q.push({ 0,0,0 });
	vis[0][0][0] = 1; // 시작점 방문 및 거리 1로 설정

	int mx = 0;
	while (!Q.empty()) {
		auto [x, y, broken] = Q.front();
		Q.pop();

		if (x == N - 1 && y == M - 1) {
			cout << vis[x][y][broken];
			return 0;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			// 1. 다음 칸이 빈 도로('0')인 경우
			if (board[nx][ny] == '0' && vis[nx][ny][broken] == 0) {
				vis[nx][ny][broken] = vis[x][y][broken] + 1;
				Q.push({ nx, ny, broken });
			}

			// 2. 다음 칸이 벽('1')이고, 아직 벽을 부순 적이 없는 경우
			if (board[nx][ny] == '1' && broken == 0 && vis[nx][ny][1] == 0) {
				vis[nx][ny][1] = vis[x][y][0] + 1;
				Q.push({ nx, ny, 1 });
			}
		}
	}
	// 도달할 수 없는 경우
	cout << -1;
	return 0;
}