//
// Created by 손민균 on 26. 11. 17.
//
#include <iostream>
#include <vector>
using namespace std;

int backtracking(int start, vector<bool>& visited, vector<vector<int>>& graph) {
    int min = INT32_MAX;
    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            int temp = graph[start][i] + backtracking(i, visited, graph);
            if (min > temp) min = temp;
            visited[i] = false;
        }
    }
    if (min == INT32_MAX) return 0;
    else return min;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < n; l++) {
                if (graph[j][l] > graph[j][i] + graph[i][l]) graph[j][l] = graph[j][i] + graph[i][l];
            }
        }
    }

    vector<bool> visited(n, false);
    visited[k] = true;
    int min = INT32_MAX;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            int temp = graph[k][i] + backtracking(i, visited, graph);
            if (min > temp) min = temp;
            visited[i] = false;
        }
    }

    cout << min << endl;
}
