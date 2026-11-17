//
// Created by 손민균 on 26. 11. 17.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<int> frag(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> frag[i];
    }

    vector<vector<int> > graph(n, vector<int>(n, -1));
    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a - 1][b - 1] = graph[b - 1][a - 1] = l;
    }

    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (graph[j][i] != -1 && graph[i][k] != -1) {
                    if ( graph[j][k] == -1 || graph[j][k] > graph[j][i] + graph[i][k]) {
                        graph[j][k] = graph[j][i] + graph[i][k];
                    }
                }
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        int recovery = 0;
        for (int j = 0; j < n; j++) {
            if (graph[i][j] <= m && graph[i][j] != -1) recovery += frag[j];
        }
        if (recovery > max) {
            max = recovery;
        }
    }

    cout << max << endl;
}