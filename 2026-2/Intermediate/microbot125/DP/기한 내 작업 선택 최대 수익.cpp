//
// Created by 손민균 on 26. 9. 29.
//
#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector< pair<int,int> > T_and_P(n);
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        cin >> T_and_P[i].first >> T_and_P[i].second;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (T_and_P[i].first - 1 + i >= n) {
            if (i == n - 1) result[i] = 0;
            else result[i] = result[i + 1];
        }
        else {
            int possible_1 = (i+1 < n)?result[i + 1]:0;
            int possible_2 = T_and_P[i].second + ((i + T_and_P[i].first < n)?result[i + T_and_P[i].first]:0);
            if (possible_1 > possible_2) result[i] = possible_1;
            else result[i] = possible_2;
        }
    }

    cout << result[0] << endl;
}