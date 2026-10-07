#include <bits/stdc++.h>
using namespace std;
int occupation = 1; // 점유 = occupation
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[502][502]; // 판을 기본 0으로 설정
bool vis[502][502]; // 칸을 이동 했었는지 기록

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 0; // 테스트 케이스의 개수입력
	cin >> T;
	for (int i = 0; i < T; i++) {
		int M = 0, N = 0, K = 0; // 순서대로 가로,세로,점유칸 개수
		cin >> M >> N >> K;
		
		for (int r = 0; r < M; r++) {
			fill(board[r], board[r] + N, 0);
			fill(vis[r], vis[r] + N, false);
		}

		int x = 0, y = 0; // 점유칸 좌표 입력 받을 거임 바로아래서
		for (int j = 0; j < K; j++) {
			//점유칸 좌표 입력
			cin >> x >> y;
			board[x][y] = occupation; // 점유칸값을 표시함.
		}
		int occnum = 0;//점유영역 개수
		for (int m = 0; m < M; m++) { //BFS
			for (int n = 0; n < N; n++) {
				if (board[m][n] == 0 || vis[m][n]) continue; //점유된칸이 아니거나 이미 간 칸이면 스킵
				occnum++; //점유영역 발견!
				queue<pair<int, int>> Q; //BFS할 큐임
				vis[m][n] = 1; //방문 표시
				Q.push({ m,n }); //현재 위치를 시작으로BFS
				while (!Q.empty()) {
					pair<int, int> cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue; // 범위 밖일 경우 넘어감
						if (vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 점유된칸이 아닐 경우
						vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
						Q.push({ nx,ny });
					}
				}
			}
		}
		cout << occnum << '\n';
		
	}

	return 0;
}