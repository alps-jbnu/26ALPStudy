//
// Created by 손민균 on 26. 10. 16.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> indegree(n, 0);
    queue<int> q;
    vector< vector<int> > graph (n, vector<int>(0));
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        vector<int> sub(num);
        for (int j = 0; j < num; j++) {
            cin >> sub[j];
            sub[j]--;
        }
        for (int j = 1; j < num; j++) {
            graph[sub[j - 1]].push_back(sub[j]);
            indegree[sub[j]]++;
        }
    }

    for (int i = 0; i< n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> result;
    while (!q.empty()) {
        int current = q.front();
        result.push_back(current);
        q.pop();
        for (int child: graph[current]) {
            indegree[child]--;
            if (indegree[child] == 0) q.push(child);
        }
    }
    if (result.size() != n) cout << 0 << endl;
    else {
        for (int i = 0; i < n; i++) {
            cout << result[i] + 1 << endl;
        }
    }
}
/*
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int main () {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > graph (n, vector<int>(0));
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        vector<int> sub(num);
        for (int j = 0; j < num; j++) {
            cin >> sub[j];
            sub[j]--;
        }
        for (int j = 1; j < num; j++) {
            graph[sub[j - 1]].push_back(sub[j]);
        }
    }
    vector<int> distance(n, -1);
    queue<int> q;
    vector<bool> is_child(n, false);
    for (int i = 0; i < n; i++) {
        for (int j : graph[i]) is_child[j] = true;
    }

    for (int i = 0; i < n; i++) {
        if (!is_child[i]) {
            distance[i] = 0;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (distance[current] > n - 1) {
            cout << 0 << endl;
            return 0;
        }
        for (int next : graph[current]) {
            if (distance[current] >= distance[next]) {
                distance[next] = distance[current] + 1;
                q.push(next);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (distance[i] == -1) {
            cout << 0 << endl;
            return 0;
        }
    }

    vector< pair<int, int> > sort_v(n);
    for (int i = 0; i < n; i++) {
        sort_v[i] = make_pair(distance[i], i);
    }
    sort(sort_v.begin(), sort_v.end());
    for (int i = 0; i < n; i++) {
        cout << sort_v[i].second + 1 << endl;
    }
    return 0;
}
*/