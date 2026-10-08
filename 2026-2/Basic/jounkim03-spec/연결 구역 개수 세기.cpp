#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
int main(){
	int t,n,m,k;
	cin>>t;
	while(t--){
		queue <pair<int,int> > q;
		int cnt = 0;
		cin>>m>>n>>k;
		int board[50][50] = {0};
		int vis[50][50] = {0};
		int dy[4] = {-1, 1, 0 , 0};
		int dx[4] = { 0, 0, -1, 1}; 
		for( int i = 0; i < k; i++){
			int x,y;
			cin>>x>>y;
			board[y][x] = 1;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(board[i][j] == 1 && vis[i][j] == 0){
					vis[i][j] = 1;
					q.push({i,j});
					while(!q.empty()){
						pair<int,int> cur = q.front();
						q.pop();
						for(int d = 0 ; d < 4; d++){
							int ny = cur.first + dy[d];
							int nx = cur.second + dx[d];
							if( ny < 0 || ny >=n || nx < 0 || nx >= m){
								continue;
							}
							if(vis[ny][nx] == 1 || board[ny][nx] == 0){
								continue;
							}
							vis[ny][nx] = 1;
							q.push({ny,nx});
						}
					}
					cnt += 1;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}