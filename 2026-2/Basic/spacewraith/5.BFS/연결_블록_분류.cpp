#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

char map[26][26];
bool visited[26][26];

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for(int i = 0; i < N; i++) {
		cin >> map[i];
	}

	int cluster_cnt = 0;
	vector<int> cluster_size;
	for(int r = 0; r < N; r++) {
		for(int c = 0; c < N; c++) {

			if(map[r][c] == '1' && !visited[r][c]) {
				//bfs 시작
				queue<pair<int, int>> q;
				int size = 1;
				q.push({r, c});
				visited[r][c] = true;
				while(!q.empty()) {
					auto [cr, cc] = q.front(); q.pop();

					for(int i = 0; i < 4; i++) {
						int nr = cr + dr[i];
						int nc = cc + dc[i];

						if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
						if(map[nr][nc] == '0' || visited[nr][nc]) continue;

						q.push({nr, nc});
						visited[nr][nc] = true;
						size++;
					}
				}

				cluster_size.push_back(size);
				cluster_cnt++;
			}

		}
	}

	sort(cluster_size.begin(), cluster_size.end());

	cout << cluster_cnt << '\n';
	for(int i : cluster_size)
		cout << i << '\n';

	return 0;
}

