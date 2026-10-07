#include <iostream>
#include <queue>
#include <utility>

using namespace std;

char map[101][101];
bool visited[100][100];
bool visited2[100][100];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for(int i = 0; i < N; i++) {
		cin >> map[i];
	}

	int cnt = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(!visited[i][j]) {

				queue<pair<int, int>> q;
				q.push({i, j});
				visited[i][j] = true;
				while(!q.empty()) {
					auto [cr, cc] = q.front(); q.pop();

					for(int k = 0; k < 4; k++) {
						int nr = cr + dr[k];
						int nc = cc + dc[k];

						if(nr >= N || nr < 0 || nc >= N || nc < 0) continue;
						if(visited[nr][nc] || map[nr][nc] != map[cr][cc]) continue;

						q.push({nr, nc});
						visited[nr][nc] = true;
					}
				}

				cnt++;
			}
		}
	}

	cout << cnt << ' ';

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(map[i][j] == 'G')
				map[i][j] = 'R';
		}
	}
	
	cnt = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(!visited2[i][j]) {

				queue<pair<int, int>> q;
				q.push({i, j});
				visited2[i][j] = true;
				while(!q.empty()) {
					auto [cr, cc] = q.front(); q.pop();

					for(int k = 0; k < 4; k++) {
						int nr = cr + dr[k];
						int nc = cc + dc[k];

						if(nr >= N || nr < 0 || nc >= N || nc < 0) continue;
						if(visited2[nr][nc] || map[nr][nc] != map[cr][cc]) continue;

						q.push({nr, nc});
						visited2[nr][nc] = true;
					}
				}

				cnt++;
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}

