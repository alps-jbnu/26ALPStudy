//
// Created by 손민균 on 26. 10. 16.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct COMPARE {
    bool operator() (const pair<pair<int, int>, long long>& a, const pair<pair<int, int>, long long>& b) {
        return a.second > b.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    priority_queue<pair<pair<int, int>, long long>, vector< pair<pair<int, int>, long long> >, COMPARE> pq;

    vector<vector<long long> > C(n, vector<long long>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> C[i][j];
        }
    }

    vector<bool> visit(n, false);
    int current = 0;
    long long cost = 0;
    visit[current] = true;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            pq.push(make_pair(make_pair(current, j), C[current][j]));
        }
        while (visit[pq.top().first.second]) pq.pop();
        pair<pair<int, int>, long long> top = pq.top();
        pq.pop();
        current = top.first.second;
        visit[top.first.second] = true;
        cost += top.second;
    }

    cout << cost << endl;

    return 0;
}