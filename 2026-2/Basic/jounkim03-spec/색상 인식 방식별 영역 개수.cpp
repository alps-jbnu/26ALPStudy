#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,r = 0 ,g = 0, b = 0, rg = 0;
	queue<pair<int,int> > q;
	int distinans;
	cin>>n;
	int board[26][26] = {0};
	int vis[26][26] = {0};
	int dx[4] = {-1,1,0,0};
	int dy[4] = {0,0,-1,1};
	for( int i = 0; i < n; i++){
		string s;
		cin>>s;
		for(int j = 0; j < n; j++){
			board[i][j] = s[j];
		}
	}
	for( int i = 0; i < n; i++){
		for( int j = 0; j < n; j++){
			if( board[i][j] == 'R' && vis[i][j] == 0){
				vis[i][j] = 1;
				q.push({i,j});
				while(!q.empty()){
					pair<int,int> cur = q.front();
					q.pop();
					for(int d = 0 ; d < 4; d++){
						int nx = cur.first + dx[d]; //상하좌우 탐색 
						int ny = cur.second + dy[d];
						if(nx < 0 || nx >= n || ny < 0 || ny >= n){
							continue;
						}
						if(vis[nx][ny] == 1 || board[nx][ny] != 'R'){
							continue;
						}
						vis[nx][ny] = 1;
						q.push({nx,ny});
					}
				}
				r += 1;
			}
		}
	}
	for( int i = 0; i < n; i++){
		for( int j = 0; j < n; j++){
			if( board[i][j] == 'B' && vis[i][j] == 0){
				vis[i][j] = 1;
				q.push({i,j});
				while(!q.empty()){
					pair<int,int> cur = q.front();
					q.pop();
					for(int d = 0 ; d < 4; d++){
						int nx = cur.first + dx[d]; //상하좌우 탐색 
						int ny = cur.second + dy[d];
						if(nx < 0 || nx >= n || ny < 0 || ny >= n){
							continue;
						}
						if(vis[nx][ny] == 1 || board[nx][ny] != 'B'){
							continue;
						}
						vis[nx][ny] = 1;
						q.push({nx,ny});
					}
				}
				b += 1;
			}
		}
	}
	for( int i = 0; i < n; i++){
		for( int j = 0; j < n; j++){
			if( board[i][j] == 'G' && vis[i][j] == 0){
				vis[i][j] = 1;
				q.push({i,j});
				while(!q.empty()){
					pair<int,int> cur = q.front();
					q.pop();
					for(int d = 0 ; d < 4; d++){
						int nx = cur.first + dx[d]; //상하좌우 탐색 
						int ny = cur.second + dy[d];
						if(nx < 0 || nx >= n || ny < 0 || ny >= n){
							continue;
						}
						if(vis[nx][ny] == 1 || board[nx][ny] != 'G'){
							continue;
						}
						vis[nx][ny] = 1;
						q.push({nx,ny});
					}
				}
				g += 1;
			}
		}
	}
	distinans = r + g + b;
	cout<<distinans<<' ';
	memset(vis,0,sizeof(vis));
	for( int i = 0; i < n; i++){
		for( int j = 0; j < n; j++){
			if( (board[i][j] == 'G' || board[i][j] == 'R') && vis[i][j] == 0){
				vis[i][j] = 1;
				q.push({i,j});
				while(!q.empty()){
					pair<int,int> cur = q.front();
					q.pop();
					for(int d = 0 ; d < 4; d++){
						int nx = cur.first + dx[d]; //상하좌우 탐색 
						int ny = cur.second + dy[d];
						if(nx < 0 || nx >= n || ny < 0 || ny >= n){
							continue;
						}
						if(vis[nx][ny] == 1 || board[nx][ny] == 'B'){
							continue;
						}
						vis[nx][ny] = 1;
						q.push({nx,ny});
					}
				}
				rg += 1;
			}
		}
	}
	int notdistinans = b+rg;
	cout<<notdistinans;
	return 0;
}