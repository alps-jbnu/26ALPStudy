#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 0;
	cin >> T;

	while(T--) {
		int M = 0, N = 0, K = 0;
		cin >> M >> N >> K;

		vector<vector<int>> map(N, vector<int>(M, 0));
		vector<vector<bool>> visited(N, vector<bool>(M, false));

		while(K--) {
			int x = 0, y = 0;

			cin >> x >> y;

			map[y][x] = 1;
		}

		int count = 0;

		for(int r  = 0; r < N; r++) {
			for(int c = 0; c < M; c++ ) {
				if(map[r][c] == 0 || visited[r][c]) continue;

				count++;
				
				//dfs시작
				queue<pair<int, int>> q;
				q.push({r, c});
				visited[r][c] = true;
				while(!q.empty()) {
					auto[cur_r, cur_c] = q.front(); q.pop();

					for(int i = 0; i < 4; i++) {
						int next_r = cur_r + dr[i];
						int next_c = cur_c + dc[i];

						if(next_r >= N || next_r < 0 || next_c >= M || next_c < 0) continue;
						if(visited[next_r][next_c] || map[next_r][next_c] == 0) continue;

						visited[next_r][next_c] = true;
						q.push({next_r, next_c});
					}
				}
			}
		}

		cout << count << '\n';
	}

	return 0;
}

