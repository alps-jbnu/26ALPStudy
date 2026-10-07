//
// Created by 손민균 on 26. 9. 27.
//
#include <iostream>
using namespace std;

int main () {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        if (N == 0) {
            cout << 1 << ' ' << 0 << endl;
            continue;
        }
        else if (N == 1) {
            cout << 0 << ' ' << 1 << endl;
            continue;
        }
        int fibo_1 = 1, fibo_2 = 1;
        for (int i = 3; i <= N; i++) {
            if (fibo_1 <= fibo_2) fibo_1 = fibo_1 + fibo_2;
            else fibo_2 = fibo_1 + fibo_2;
        }
        if (fibo_1 > fibo_2) cout << fibo_2 << ' ' << fibo_1 << endl;
        else cout << fibo_1 << ' ' << fibo_2 << endl;
    }

    return 0;
}