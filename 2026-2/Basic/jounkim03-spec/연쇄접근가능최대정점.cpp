#include <bits/stdc++.h>
using namespace std;

int main(){
	int m,n;
	cin>>n>>m;
	vector<int> cnt(n+1,0);
	vector<vector<int> > adj(n+1);
	for(int i = 0; i < m; i++){
		int u,v;
		cin>>u>>v;
		adj[v].push_back(u);
	}
	queue<int> q;
	for(int i = 1; i < n+1; i++){
		vector<int> vis(n+1,0);
		q.push(i);
		vis[i] = 1;
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(int j = 0; j < adj[cur].size(); j++){
				int nxt = adj[cur][j];
				if(vis[nxt] == 1){
					continue;
				}
				cnt[i]++;
				q.push(nxt);
				vis[nxt] = 1;
			}
		}
	}
	int max = 0;
	for(int i = 1; i < n+1; i++){
		if(max < cnt[i]){
			max = cnt[i];
		}
	}
	for(int i = 1; i < n+1; i++){
		if(cnt[i] == max){
			cout << i <<" ";
		}
	}
	return 0;
}