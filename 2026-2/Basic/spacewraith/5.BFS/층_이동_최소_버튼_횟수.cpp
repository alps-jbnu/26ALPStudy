#include <iostream>
#include <queue>

using namespace std;

int dist[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int F, S, G, U, D;
	
	cin >> F >> S >> G >> U >> D;

	if(S == G) {
		cout << 0 << '\n';
		return 0;
	}
	
	int df[] = {U, -D};

	queue<int> q;
	q.push(S);
	dist[S] = 1;
	while(!q.empty()) {
		int cur_f = q.front(); q.pop();

		for(int i = 0; i < 2; i++) {
			int nxt_f = cur_f + df[i];

			if(nxt_f < 1 || nxt_f > F) continue;
			if(dist[nxt_f]) continue;

			q.push(nxt_f);
			dist[nxt_f] = dist[cur_f] + 1;

			if(nxt_f == G) {
				cout << dist[nxt_f] - 1 << '\n';
				return 0;
			}
		}

		
	}

	cout << "use the stairs\n";

	return 0;
}

