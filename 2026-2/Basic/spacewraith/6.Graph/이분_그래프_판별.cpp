#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int K;
	cin >> K;

	while(K--) {
		int V, E;

		cin >> V >> E;
	
		vector<vector<int>> adj(V + 1);
		vector<int> set(V + 1, 0);

		for(int i = 0; i < E; i++) {
			int u, v;

			cin >> u >> v;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		queue<int> q;
		q.push(1);
		set[1] = 1;
		bool flag = true;
		while(!q.empty()) {
			int cur = q.front(); q.pop();

			for(int next : adj[cur]) {
				if(set[next] == 0) {
					q.push(next);
					set[next] = -set[cur];
				} else if(set[next] == set[cur]) {
					flag = false;
					break;
				}
			}

			if(!flag) break;
		}

		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}


	return 0;
}

