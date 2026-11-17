//
// Created by 손민균 on 26. 11. 17.
//
#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > graph (n, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
        int u, v, e;
        cin >> u >> v >> e;
        graph[u - 1][v - 1] = e;
    }

    int a, b;
    cin >> a >> b;

    vector<bool> visited(n, false);
    vector<int> distance(n, -1);
    visited[a - 1] = true;
    distance[a - 1] = 0;
    int last = a - 1;
    for (int i = 0; i < n; i++) {
        int min = INT32_MAX;
        int next = last;
        for (int j = 0; j < n; j++) {
            if (graph[last][j] != -1 && (distance[j] == -1 || distance[j] > graph[last][j] + distance[last])) distance[j] = graph[last][j] + distance[last];
            if (!visited[j] && distance[j] != -1 && distance[j] < min) {
                min = distance[j];
                next = j;
            }
        }
        last = next;
        visited[next] = true;
    }

    cout << distance[b - 1] << endl;
}