//
// Created by 손민균 on 26. 9. 13.
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

int binary_search_for_last_index(const vector< vector<int> >& arr, const vector<int>& target, int start, int end) {
    if (target == arr[end]) return end;
    if (start + 1 == end) return start;
    if (target == arr[(start + end) / 2]) return binary_search_for_last_index(arr, target, (start + end) / 2, end);
    else return binary_search_for_last_index(arr, target, start, (start + end) / 2);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector< vector<int> > arr(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> pq;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            pq.emplace(x, j);
        }
        int sequence_label = 0;
        int before = pq.top().first;
        arr[i][pq.top().second] = sequence_label;
        pq.pop();
        for (int j = 1; j < n; j++) {
            int current = pq.top().first;
            if (current == before) arr[i][pq.top().second] = sequence_label;
            else {
                arr[i][pq.top().second] = ++sequence_label;
                before = current;
            }
            pq.pop();
        }
    }

    sort(arr.begin(), arr.end());
    int total_pair = 0;
    int current_index = 0;
    while (true) {
        int last_index = binary_search_for_last_index(arr, arr[current_index], current_index, m - 1);
        total_pair += (last_index - current_index) * (last_index - current_index + 1) / 2;
        if (last_index == m - 1) break;
        current_index = last_index + 1;
    }

    cout << total_pair << endl;
    return 0;
}