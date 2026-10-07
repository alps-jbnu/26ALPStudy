#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[101001];
int dist[101001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K, M;

	cin >> N >> K >> M;

	int next_idx = N + 1;
	for(int i = 0; i < M; i++) {
		for(int j = 0; j < K; j++) {
			int node;

			cin >> node;
			adj[node].push_back(next_idx);
			adj[next_idx].push_back(node);
		}	

		next_idx++;
	}


	queue<int> q;
	q.push(1);
	dist[1] = 1;
	while(!q.empty()) {
		int cur = q.front(); q.pop();

		if(cur == N) {
			cout << dist[cur] / 2 + 1<< '\n';
			return 0;
		}

		for(int next : adj[cur]) {
			if(dist[next] != 0) continue;

			q.push(next);
			dist[next] = dist[cur] + 1;
		}
	}

	cout << -1 << '\n';

	return 0;
}

