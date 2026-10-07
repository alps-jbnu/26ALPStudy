#include <bits/stdc++.h>
using namespace std;

int board[105][105][105];
int paas[105][105][105];
int M, N, H;
int dx[6] = { 1, 0 ,-1, 0, 0,0 };
int dy[6] = { 0,1,0,-1, 0,0};
int dz[6] = { 0,0,0,0,1,-1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N >> H; //가로 세로 높이 입력받음.
	queue<tuple<int, int, int>> Q;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> board[k][j][i];
				paas[k][j][i] = -1;
				if (board[k][j][i] == 1) {
					Q.push({ k, j, i });
					paas[k][j][i] = 0;
				}
			}
		}
	}
	/*for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cout << board[k][j][i] << ' ';
			}
			cout << '\n';
		}
	}*/

	while (!Q.empty()) {
		tuple<int, int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int nz = get<2>(cur) + dz[dir];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue; // 범위 밖일 경우 넘어감
			if (paas[nx][ny][nz] >= 0 || board[nx][ny][nz] != 0) continue; // 이미 방문한 칸이거나 안익은 칸이 아닐 경우
			
			paas[nx][ny][nz] = paas[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1; // (nx, ny, nz)를 방문했고 시간이 이만큼 지났음을 명시
			Q.push({ nx,ny,nz });
		}
	}

	int topa = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				// 익지 않은 토마토가 남아있다면 -1 출력 후 종료
				if (board[k][j][i] == 0 && paas[k][j][i] == -1) {
					cout << -1;
					return 0;
				}
				topa = max(topa, paas[k][j][i]);
			}
		}
	}
	cout << topa;
	return 0;
}
