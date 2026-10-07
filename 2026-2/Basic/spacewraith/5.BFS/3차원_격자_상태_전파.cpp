#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int dh[] = {1, -1, 0, 0 ,0, 0};
int dr[] = {0, 0, 1, -1, 0, 0};
int dc[] = {0, 0, 0, 0, 1, -1};

int map[100][100][100]; 
int dist[100][100][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N, H;
	queue<tuple<int, int, int>> q;

	cin >> M >> N >> H;

	for(int i = 0; i < H; i++){
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < M; k++) {
				cin >> map[i][j][k];

				if(map[i][j][k] == 1) {
					q.push({i, j, k});
				} else {
					dist[i][j][k] = -1;
				}
			}
		}
	}

	while(!q.empty()) {
		auto [ch, cr, cc] = q.front(); q.pop();

		for(int i = 0; i < 6; i++) {
			int nh = ch + dh[i];
			int nr = cr + dr[i];
			int nc = cc + dc[i];

			if(nh >= H || nh < 0 || nr >= N || nr < 0 || nc >= M || nc < 0)
				continue;
			if(dist[nh][nr][nc] >= 0 || map[nh][nr][nc] == -1) continue;

			q.push({nh, nr, nc});
			dist[nh][nr][nc] = dist[ch][cr][cc] + 1;
		}
	}

	
	int ans = 0;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < M; k++) {

				if(map[i][j][k] != -1) {
					ans = max(ans, dist[i][j][k]);

					if(dist[i][j][k] == -1) {
						cout << -1 << '\n';
						return 0;
					}
				}

			}
		}
	}

	cout << ans << '\n';
	
	return 0;
}

