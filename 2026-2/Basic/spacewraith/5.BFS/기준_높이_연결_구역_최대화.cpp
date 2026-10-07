#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int map[100][100];
int dr[] = {1, 0, 0, -1};
int dc[] = {0, 1, -1, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	
	cin >> N;

	int min_height = 1000;
	int max_height = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++) {
			cin >> map[i][j];
			
			if(map[i][j] < min_height)
				min_height = map[i][j];

			if(map[i][j] > max_height)
				max_height = map[i][j];
		}
	}


	int max_connected = 1;
	for(int h = min_height; h < max_height; h++) {
		
		//높이 h에서의 연결구역 탐색 시작
		int area_cnt = 0;
		bool visited[100][100] = {0, };
		for(int	r = 0; r < N; r++) {
			for(int c = 0; c < N; c++) {
				
				if(map[r][c] > h && !visited[r][c]) {
					//bfs 시작
					queue<pair<int, int>> q;
					q.push({r, c});
					visited[r][c] = true;
					while(!q.empty()) {
						auto [cr, cc] = q.front(); q.pop();

						for(int i = 0; i < 4; i++) {
							int nr = cr + dr[i];
							int nc = cc + dc[i];

							if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
							if(map[nr][nc] <= h || visited[nr][nc]) continue;

							q.push({nr, nc});
							visited[nr][nc] = true;
						}
					}

					area_cnt++;
				}
			}
		}

		if(area_cnt > max_connected)
			max_connected = area_cnt;

	}

	cout << max_connected << '\n';

	return 0;
}

