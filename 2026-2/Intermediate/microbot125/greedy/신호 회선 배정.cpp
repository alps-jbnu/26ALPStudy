//
// Created by 손민균 on 26. 10. 5.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

int main () {
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    int max_Simultaneous_operation = 1;
    pq.push(v[0]);
    for (int i = 1; i < n; i++) {
        while (!pq.empty() && pq.top().second <= v[i].first) {
            pq.pop();
        }
        pq.push(v[i]);
        if (pq.size() > max_Simultaneous_operation) max_Simultaneous_operation = pq.size();
    }

    cout << max_Simultaneous_operation << endl;

    return 0;
}