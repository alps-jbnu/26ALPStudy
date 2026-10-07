//
// Created by 손민균 on 26. 9. 28.
//
#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<long long> number(10, 1);
    vector<long long> number2(10, 1);
    number[0] = 0;
    number2[0] = 0;

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        number[0] = number2[1];
        number[1] = number2[0] + number2[2];
        number[2] = number2[1] + number2[3];
        number[3] = number2[2] + number2[4];
        number[4] = number2[3] + number2[5];
        number[5] = number2[4] + number2[6];
        number[6] = number2[5] + number2[7];
        number[7] = number2[6] + number2[8];
        number[8] = number2[7] + number2[9];
        number[9] = number2[8];
        for (int j = 0; j < 10; j++) {
            number[j] %= 1000000000;
            number2[j] = number[j];
        }
    }
    long long sum = 0;
    for (int j = 0; j < 10; j++) {
        sum += number[j];
    }
    cout << sum % 1000000000 << endl;
    return 0;
}