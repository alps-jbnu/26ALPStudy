#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> sum(n+1,0);
	vector<vector<int> > adj(n+1);
	for( int i = 0; i < m; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int> q;
	for(int i = 1; i < n+1; i++){
		vector<int> vis(n+1,0);
		vector<int> dist(n+1,0);
		q.push(i);
		vis[i] = 1;
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(int j = 0; j < adj[cur].size();j++){
				int nxt = adj[cur][j];
				if( vis[nxt] == 1){
					continue;
				}
				q.push(nxt);
				vis[nxt] = 1;
				dist[nxt] = dist[cur] + 1;
			}
		}
		for(int j = 1; j < n+1; j++){
			sum[i] += dist[j];
		}
	}
	int ans = 1;
	for(int i = 2; i < n+1; i++){
		if(sum[i] < sum[ans]){
			ans = i;
		}
	}
	cout << ans;
	return 0;
}