#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int map[1001][1001];
int dist[2][1001][1001];

int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N = 0, M = 0;

	cin >> N >> M;

	for(int i = 1; i <= N; i++) {
		string s;

		cin >> s;

		for(int j = 0; j < M; j++) {
			map[i][j + 1] = s[j] - '0';
		}
	}

	//bfs시작
	queue<tuple<int, int, int>> q;
	q.push({1, 1, 0});
	dist[0][1][1] = 1;
	while(!q.empty()){
		auto [cr, cc, is_break] = q.front(); q.pop();

		//목적지면 프로그램 종료
		if(cr == N && cc == M) {
			cout << dist[is_break][cr][cc] << '\n';
			return 0;
		}

		for(int k = 0; k < 4; k++) {
			int nr = cr + dr[k];
			int nc = cc + dc[k];
			int nbreak = is_break; 

			//범위 검사
			if(nr > N || nr < 1 || nc > M || nc < 1) continue;
			
			//벽 검사
			if(map[nr][nc] == 1) {
				if(is_break){ //이미 부쉈으면
				   	continue;
				} else { 
					nbreak = 1;
				}
			}
			
			//방문 검사
			if(dist[nbreak][nr][nc]) continue;

			dist[nbreak][nr][nc] = dist[is_break][cr][cc] + 1;
			q.push({nr, nc, nbreak});
		}
	}


	cout << -1 << '\n';
	
	return 0;
}

