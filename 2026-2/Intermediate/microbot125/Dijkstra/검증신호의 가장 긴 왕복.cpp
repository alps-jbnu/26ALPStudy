//
// Created by 손민균 on 26. 10. 15.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<int> > graph (n, vector<int>(n, -1));
    vector<vector<int> > inverse_graph (n, vector<int>(n, -1));

    for (int i = 0; i < m; i++) {
        int s, e, t;
        cin >> s >> e >> t;
        graph[s - 1][e - 1] = t;
        inverse_graph[e - 1][s - 1] = t;
    }

    vector<bool> visit(n, false);
    vector<int> distances (n, -1);
    distances[x - 1] = 0;
    visit[x - 1] = true;
    int last = x - 1;
    for (int i = 0; i < n; i++) {
        int minimum = INT32_MAX;
        int next = last;
        for (int j = 0; j < n; j++) {
            if (graph[last][j] != -1 && (distances[j] == -1 || distances[j] > distances[last] + graph[last][j])){
                distances[j] = distances[last] + graph[last][j];
            }
            if (visit[j] == false && distances[j] != -1 && minimum > distances[j]) {
                next = j;
                minimum = distances[j];
            }
        }
        last = next;
        visit[next] = true;
    }

    fill(visit.begin(), visit.end(), false);
    vector<int> inverse_distances (n, -1);
    inverse_distances[x - 1] = 0;
    visit[x - 1] = true;
    last = x - 1;
    for (int i = 0; i < n; i++) {
        int minimum = INT32_MAX;
        int next = last;
        for (int j = 0; j < n; j++) {
            if (inverse_graph[last][j] != -1 && (inverse_distances[j] == -1 || inverse_distances[j] > inverse_distances[last] + inverse_graph[last][j])){
                inverse_distances[j] = inverse_distances[last] + inverse_graph[last][j];
            }
            if (visit[j] == false && inverse_distances[j] != -1 && minimum > inverse_distances[j]) {
                next = j;
                minimum = inverse_distances[j];
            }
        }
        last = next;
        visit[next] = true;
    }

    int minimum = 0;
    for (int i = 0; i < n; i++) {
        if (minimum < distances[i] + inverse_distances[i]) {
            minimum = distances[i] + inverse_distances[i];
        }
    }

    cout << minimum << endl;
}