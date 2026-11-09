//
// Created by 손민균 on 26. 10. 15.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int> > graph(v, vector<int>(v, -1));
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1][b - 1] = c;
    }

    for (int i = 0; i < v; i++) {
        graph[i][i] = 0;
    }

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            for (int k = 0; k < v; k++) {
                if (j == i) continue;
                if (graph[j][i] != -1 && graph[i][k] != -1) {
                    if (graph[j][k] == -1) {
                        graph[j][k] = graph[j][i] + graph[i][k];
                    }
                    else if (graph[j][k] > graph[j][i] + graph[i][k]) {
                        graph[j][k] = graph[j][i] + graph[i][k];
                    }
                }
            }
        }
    }

    int min = INT32_MAX;
    for (int i = 0; i < v; i++) {
        for (int j = i + 1; j < v; j++) {
            if (graph[i][j] != -1 && graph[j][i] != -1 && min > graph[i][j] + graph[j][i]) min = graph[i][j] + graph[j][i];
        }
    }

    if (min == INT32_MAX) cout << "-1" << endl;
    else cout << min << endl;

    return 0;
}