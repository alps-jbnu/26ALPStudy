#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;

	cin >> N >> M;
	
	vector<vector<int>> adj(N + 1);	
	vector<int> dist(N + 1, -1);

	for(int i = 0; i < M; i++) {
		int a, b;

		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	int max_dist = 0;
	while(!q.empty()) {
		int cur = q.front(); q.pop();

		for(int next : adj[cur]) {
			if(dist[next] != -1) continue;

			q.push(next);
			dist[next] = dist[cur] + 1;

			max_dist = max(max_dist, dist[next]);
		}
	}

	
	bool is_first = true;
	int cnt = 0;
	for(int i = 1; i <= N; i++) {
		if(dist[i] == max_dist) {
			cnt++;

			if(is_first) {
				cout << i << ' ' << dist[i] << ' ';
				is_first = false;
			}
		}
	}

	cout << cnt << '\n';
	
	return 0;
}

