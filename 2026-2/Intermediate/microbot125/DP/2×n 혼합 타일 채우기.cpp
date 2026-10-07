//
// Created by 손민균 on 26. 9. 28.
//
#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;

    int tile_1 = 1;
    int tile_2 = 3;
    for (int i = 3; i <= n; i++) {
        if (i%2 == 1) {
            tile_1 = tile_1 * 2 + tile_2;
            tile_1 %= 10007;
        }
        else {
            tile_2 = tile_2 * 2 + tile_1;
            tile_2 %= 10007;
        }
    }

    if (n%2 == 1) cout << tile_1 << endl;
    else cout << tile_2 << endl;

    return 0;
}