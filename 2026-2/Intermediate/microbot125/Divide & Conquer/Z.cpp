//
// Created by 손민균 on 26. 10. 11.
//
#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;

    long long r, c;
    cin >> r >> c;
    long long two_square = 1;
    for (int i = 0; i < n - 1; i++) {
        two_square = two_square * 2;
    }

    long long total = 0;
    for (int i = 0; i < n; i++) {
        if (r / two_square == 1) total += two_square * two_square * 2;
        if (c / two_square == 1) total += two_square * two_square;
        r %= two_square;
        c %= two_square;
        two_square /= 2;
    }
    cout << total << endl;

    return 0;
}