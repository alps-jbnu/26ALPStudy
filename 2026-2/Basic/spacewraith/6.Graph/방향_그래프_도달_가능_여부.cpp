#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int> adj[101];
int visited[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;

	cin >> N;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			int n;

			cin >> n;
			if(n == 1)
				adj[i].push_back(j);
		}
	}

	for(int i = 0; i < N; i++) {
		fill(visited, visited + 101, 0);

		queue<int> q;
		q.push(i);
		while(!q.empty()) {
			int cur = q.front(); q.pop();

			for(int next : adj[cur]) {
				if(!visited[next]) {
					q.push(next);
					visited[next] = 1;
				}
			}
		}

		for(int j = 0; j < N; j++) {
			cout << visited[j] << ' ';
		}

		cout << '\n';

	}
	return 0;
}
