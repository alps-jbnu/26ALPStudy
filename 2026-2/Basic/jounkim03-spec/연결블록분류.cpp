#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,cl = 0,area = 0;
	vector<int> arr;
	cin >> n;
	int board[25][25];
	int vis[25][25] = {0};
	int dx[4] = {-1,1,0,0};
	int dy[4] = {0,0,-1,1};
	for( int i = 0; i < n; i++){
		string s;
		cin>>s;
		for(int j = 0; j < n; j++){
			board[i][j] = s[j]-'0';
		}
	}
	queue<pair<int ,int> > q;
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j < n ; j++){
			if(board[i][j] == 1 && vis[i][j] == 0){
				q.push({i,j});
				vis[i][j] = 1;
				area = 1;
				while(!q.empty()){
					pair<int,int> cur = q.front();
					q.pop();
					for(int d = 0; d < 4; d++){
						int nx,ny;
						nx = cur.first + dx[d];
						ny = cur.second + dy[d];
						if(nx < 0 || nx >= n || ny < 0 || ny >=n){
							continue;
						}
						if(vis[nx][ny] == 1 || board[nx][ny] == 0){
							continue;
						}
						vis[nx][ny] = 1;
						q.push({nx,ny});
						area++;
					}
				}
				cl++;
				arr.push_back(area);
				area = 0;
			}
		}
	}
	sort(arr.begin(), arr.end());
	cout<<cl<<'\n';
	for (int i = 0 ; i < arr.size(); i++) {
    	cout << arr[i] << '\n';
	}
	return 0;
}