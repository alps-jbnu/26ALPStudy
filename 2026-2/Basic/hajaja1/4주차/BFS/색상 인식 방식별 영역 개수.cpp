#include <bits/stdc++.h>
using namespace std;
int occupation = 1; // 점유 = occupation
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string board[502]; // 판을 문자열로 받음
bool vis[502][502]; // 칸을 이동 했었는지 기록

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N = 0; // 정사각 격자의 한변의 길이
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
	int RGsamenum = 0;//RG를 같은색으로 볼때 색깔영역 개수
	int RGdiffnum = 0;//RG를 다른색으로 볼때 색깔영역 개수
	int Bnum = 0;//B영역의 개수
	for (int cnt = 0; cnt < 2; cnt++) {
		for (int i = 0; i < N; i++) {
			fill(vis[i], vis[i] + N, false);
		}
		if (cnt == 0) { // RG를 같은색으로 볼경우 BFS
			for (int m = 0; m < N; m++) { //BFS
				for (int n = 0; n < N; n++) {
					if (board[m][n] == 'B' || vis[m][n]) continue; //B색이거나 이미 간 칸이면 스킵
					RGsamenum++; //점유영역 발견!
					queue<pair<int, int>> Q; //BFS할 큐임
					vis[m][n] = 1; //방문 표시
					Q.push({ m,n }); //현재 위치를 시작으로BFS
					while (!Q.empty()) {
						pair<int, int> cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // 범위 밖일 경우 넘어감
							if (vis[nx][ny] || board[nx][ny] == 'B') continue; // 이미 방문한 칸이거나 R,G칸이 아닐 경우
							vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
							Q.push({ nx,ny });
						}
					}
				}
			}
			for (int m = 0; m < N; m++) { //BFS
				for (int n = 0; n < N; n++) {
					if (board[m][n] != 'B' || vis[m][n]) continue; //R,G색이거나 이미 간 칸이면 스킵
					Bnum++; //점유영역 발견!
					queue<pair<int, int>> Q; //BFS할 큐임
					vis[m][n] = 1; //방문 표시
					Q.push({ m,n }); //현재 위치를 시작으로BFS
					while (!Q.empty()) {
						pair<int, int> cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // 범위 밖일 경우 넘어감
							if (vis[nx][ny] || board[nx][ny] != 'B') continue; // 이미 방문한 칸이거나 B칸이 아닐 경우
							vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
							Q.push({ nx,ny });
						}
					}
				}
			}
		}
		else {// RG를 다른색으로 볼경우 BFS
			for (int m = 0; m < N; m++) { //BFS
				for (int n = 0; n < N; n++) {
					if (board[m][n] != 'R' || vis[m][n]) continue; //B,G색이거나 이미 간 칸이면 스킵
					RGdiffnum++; //점유영역 발견!
					queue<pair<int, int>> Q; //BFS할 큐임
					vis[m][n] = 1; //방문 표시
					Q.push({ m,n }); //현재 위치를 시작으로BFS
					while (!Q.empty()) {
						pair<int, int> cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // 범위 밖일 경우 넘어감
							if (vis[nx][ny] || board[nx][ny] != 'R') continue; // 이미 방문한 칸이거나 R칸이 아닐 경우
							vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
							Q.push({ nx,ny });
						}
					}
				}
			}
			for (int m = 0; m < N; m++) { //BFS
				for (int n = 0; n < N; n++) {
					if (board[m][n] != 'G' || vis[m][n]) continue; //B,R색이거나 이미 간 칸이면 스킵
					RGdiffnum++; //점유영역 발견!
					queue<pair<int, int>> Q; //BFS할 큐임
					vis[m][n] = 1; //방문 표시
					Q.push({ m,n }); //현재 위치를 시작으로BFS
					while (!Q.empty()) {
						pair<int, int> cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue; // 범위 밖일 경우 넘어감
							if (vis[nx][ny] || board[nx][ny] != 'G') continue; // 이미 방문한 칸이거나 R칸이 아닐 경우
							vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
							Q.push({ nx,ny });
						}
					}
				}
			}
		}
	}
		
		cout << RGdiffnum + Bnum << ' ' << RGsamenum + Bnum;

	return 0;
}