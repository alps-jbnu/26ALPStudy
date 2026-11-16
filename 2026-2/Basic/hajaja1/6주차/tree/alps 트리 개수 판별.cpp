#include <iostream>
#include <vector>

using namespace std;

void dfs(int curr, const vector<vector<int>>& adj, vector<bool>& visited, int& nodes, int& edges) {
    visited[curr] = true;
    nodes++;
    edges += adj[curr].size(); // 연결된 간선 수 누적

    for (int next : adj[curr]) {
        if (!visited[next]) {
            dfs(next, adj, visited, nodes, edges);
        }
    }
}

void solve() {
    int case_idx = 1;
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n + 1, false);
        int tree_count = 0;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                int nodes = 0;
                int edges = 0;
                dfs(i, adj, visited, nodes, edges);

                // 무방향 그래프에서 간선 개수는 차수의 합 / 2
                // 트리의 조건: 정점 수 - 간선 수 == 1
                if (nodes - (edges / 2) == 1) {
                    tree_count++;
                }
            }
        }

        // 출력 형식 맞추기
        cout << "Case " << case_idx++ << ": ";
        if (tree_count == 0) {
            cout << "No trees.\n";
        }
        else if (tree_count == 1) {
            cout << "There is one tree.\n";
        }
        else {
            cout << "A forest of " << tree_count << " trees.\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}