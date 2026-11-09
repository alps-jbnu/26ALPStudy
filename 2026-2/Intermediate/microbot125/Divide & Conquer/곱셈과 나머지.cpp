//
// Created by 손민균 on 26. 10. 12.
//
#include <iostream>
using namespace std;

int mul_and_remain(int a, int b, int c) {
    if (b == 1) return a;
    if (b % 2 == 0) {
        long long temp = mul_and_remain(a, b / 2, c);
        temp *= temp;
        temp %= c;
        return temp;
    }
    else {
        long long temp = mul_and_remain(a, b / 2, c);
        temp *= temp;
        temp %= c;
        temp *= a;
        temp %= c;
        return temp;
    }
}

int main () {
    int a, b, c;
    cin >> a >> b >> c;

    cout << mul_and_remain(a, b, c) << endl;

    return 0;
}