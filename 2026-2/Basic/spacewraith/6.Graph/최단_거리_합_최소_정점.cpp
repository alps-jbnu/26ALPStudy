#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[101];
int dist[101];
int dist_sums[101]; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;

	cin >> N >> M;

	for(int i = 0; i < M; i++) {
		int A, B;

		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	int min_dist_sum = 10000000;
	for(int i = 1; i <= N; i++) {
		fill(dist, dist + N + 1, -1);
		
		queue<int> q;
		q.push(i);
		dist[i] = 0;
		int dist_sum = 0;
		while(!q.empty()) {
			int cur = q.front(); q.pop();

			for(int next : adj[cur]) {
				if(dist[next] >= 0) continue;

				q.push(next);
				dist[next] = dist[cur] + 1;
				dist_sum += dist[next];
			}
		}
		
		dist_sums[i] = dist_sum;
		min_dist_sum = min(min_dist_sum, dist_sum);

	}

	for(int i = 1; i <= N; i++){

		if(dist_sums[i] == min_dist_sum) {
			cout << i << '\n';
			break;
		} 
	}

	return 0;
}

