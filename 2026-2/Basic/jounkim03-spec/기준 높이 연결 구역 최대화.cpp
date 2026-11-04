#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,x,cnt = 0;
	queue<pair<int,int> > q;
	vector<int> ans;
	cin>>n;
	int board[100][100] = {0};
	int vis[100][100] = {0};
	int dx[4] = {-1,1,0,0};
	int dy[4] = {0,0,-1,1};
	for( int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>x;
			board[i][j] = x;
		}
	}
	for(int h = 1; h <= 100; h++){
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < n; j++){
				if( board[i][j] >= h && vis[i][j] == 0){
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
							if(vis[nx][ny] == 1 || board[nx][ny] < h){
								continue;
							}
							vis[nx][ny] = 1;
							q.push({nx,ny});
						}
					}
					cnt+=1;
				}
			}
		}
		ans.push_back(cnt);
		cnt = 0;
	}
	sort(ans.begin(),ans.end());
	int s = ans.size();
	cout<<ans[s-1]<<endl;
	return 0;
}