#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int dist[101];
int scores[101];
vector<int> adj[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	while(true) {
		int a, b;

		cin >> a >> b;

		if(a == -1 && b == -1) break;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int min_score = 10000;
	for(int i = 1; i <= N; i++) {
		//dist 초기화
		fill(dist, dist + N + 1, -1);

		queue<int> q;
		q.push(i);
		dist[i] = 0;
		int max_dist = 0;
		while(!q.empty()) {
			int cur = q.front(); q.pop();

			for(int next : adj[cur]) {
				if(dist[next] == -1) {
					q.push(next);
					dist[next] = dist[cur] + 1;

					max_dist = max(max_dist, dist[next]);
				}
			}
		}

		scores[i] = max_dist;
		min_score = min(min_score, scores[i]);

	}

	cout << min_score << ' ' << count(scores, scores + N + 1, min_score) << '\n';
	for(int i = 1; i <= N; i++) {
		if(scores[i] == min_score)
			cout << i << ' ';
	}

	cout << '\n';
	
	return 0;
}

