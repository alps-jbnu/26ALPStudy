//
// Created by 손민균 on 26. 10. 12.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> histogram(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> histogram[i];
    }

    stack< pair<int, int> > s;

    long long max = 0;
    for (int i = 0; i <= n + 1; i++) {
        if (s.empty() || histogram[i] >= s.top().first) {
            s.emplace(histogram[i], i);
        }
        else {
            while (!s.empty() && s.top().first > histogram[i]) {
                pair<int, int> t = s.top();
                s.pop();
                if (max < ((long long) t.first) * (i - s.top().second - 1)) {
                    max = ((long long) t.first) * (i - s.top().second - 1);
                }
            }
            s.emplace(histogram[i], i);
        }
    }

    cout << max << endl;

    return 0;
}