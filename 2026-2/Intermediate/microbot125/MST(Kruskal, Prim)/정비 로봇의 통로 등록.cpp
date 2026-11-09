//
// Created by 손민균 on 26. 10. 16.
//
#include <iostream>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
        }
        cout << n - 1 << endl;
    }
}