#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[100001];
int dist[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K, M;

	cin >> N >> K >> M;

	for(int i = 0; i < M; i++) {
		vector<int> nodes;

		for(int j = 0; j < K; j++) {
			int node;

			cin >> node;
			nodes.push_back(node);
		}	

		for(int start : nodes) {
			for(int dest : nodes) {
				if(start != dest) {
					adj[start].push_back(dest);
				}
			}
		}
	}


	queue<int> q;
	q.push(1);
	dist[1] = 1;
	while(!q.empty()) {
		int cur = q.front(); q.pop();

		for(int next : adj[cur]) {
			if(dist[next] != 0) continue;

			q.push(next);
			dist[next] = dist[cur] + 1;

			if(next == N) {
				cout << dist[next] << '\n';
				return 0;
			}
		}
	}

	cout << -1 << '\n';

	return 0;
}

