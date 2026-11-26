//
// Created by 손민균 on 26. 11. 16.
//
#include <iostream>
#include <vector>
using namespace std;

int distance(int start, int end, const vector<vector<int> > &graph, int n) {
    vector<bool> visited(n, false);
    vector<int> distance(n, -1);
    visited[start] = true;
    distance[start] = 0;
    int last = start;
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

    return distance[end];
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<int> > graph(n, vector<int>(n, -1));
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1][b - 1] = c;
        graph[b - 1][a - 1] = c;
    }

    int v1, v2;
    cin >> v1 >> v2;

    int oneToV1 = distance(0, v1 - 1, graph, n);
    int oneToV2 = distance(0, v2 - 1, graph, n);
    int v1ToV2 = distance(v1 - 1, v2 - 1, graph, n);
    int v1ToN = distance(v1 - 1, n - 1, graph, n);
    int v2ToN = distance(v2 - 1, n - 1, graph, n);

    if ((oneToV1 == -1 && oneToV2 == -1) || v1ToV2 == -1 || (v1ToN == -1 && v2ToN == -1)) cout << -1 << endl;
    else {
        int v1V2 = -1;
        int v2V1 = -1;
        if (oneToV1 != -1 && v2ToN != -1) v1V2 = oneToV1 + v1ToV2 + v2ToN;
        if (oneToV2 != -1 && v1ToN != -1) v2V1 = oneToV2 + v1ToV2 + v1ToN;
        if (v1V2 == -1) cout << v2V1 << endl;
        else if (v2V1 == -1) cout << v1V2 << endl;
        else cout << (v1V2 < v2V1 ? v1V2 : v2V1) << endl;
    }
}