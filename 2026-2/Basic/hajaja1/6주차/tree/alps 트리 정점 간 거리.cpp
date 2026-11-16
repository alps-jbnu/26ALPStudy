#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int to;
    int cost;
};

int N, M;
vector<vector<Edge>> adj;

int get_distance(int start, int target) {
    vector<int> dist(N + 1, -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == target) {
            return dist[curr];
        }

        for (const auto& edge : adj[curr]) {
            if (dist[edge.to] == -1) {
                dist[edge.to] = dist[curr] + edge.cost;
                q.push(edge.to);
            }
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    adj.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        cout << get_distance(u, v) << "\n";
    }

    return 0;
}
