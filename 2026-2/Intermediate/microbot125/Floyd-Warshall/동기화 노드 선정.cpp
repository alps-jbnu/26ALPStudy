//
// Created by 손민균 on 26. 11. 17.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a - 1][b - 1] = t;
    }
    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (graph[j][i] != -1 && graph[i][k] != -1) {
                    if (graph[j][k] == -1 || graph[j][k] > graph[j][i] + graph[i][k]) {
                        graph[j][k] = graph[j][i] + graph[i][k];
                    }
                }
            }
        }
    }

    int k;
    cin >> k;
    vector<int> start_nodes(k);
    for (int i = 0; i < k; i++) {
        cin >> start_nodes[i];
        start_nodes[i]--;
    }

    int min = INT32_MAX;
    vector<int> min_nodes(0);
    for (int i = 0; i < n; i++) {
        int max = -1;
        for (int j = 0; j < k; j++) {
            if (graph[start_nodes[j]][i] != -1 && graph[i][start_nodes[j]] != -1 && max < graph[i][start_nodes[j]] + graph[start_nodes[j]][i]) {
                max = graph[i][start_nodes[j]] + graph[start_nodes[j]][i];
            }
        }
        if (max == -1) continue;
        else if (max < min) {
            min = max;
            min_nodes = vector<int>(0);
            min_nodes.push_back(i);
        }
        else if (max == min) {
            min_nodes.push_back(i);
        }
    }

    for (int i : min_nodes) {
        cout << i + 1 << " ";
    }
}