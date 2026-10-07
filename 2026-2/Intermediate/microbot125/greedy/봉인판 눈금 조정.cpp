//
// Created by 손민균 on 26. 10. 5.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> plate(n);
    for (int i = 0; i < n; i++) {
        cin >> plate[i];
    }
    int result = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (plate[i] >= plate[i + 1]) {
            result += plate[i] - plate[i + 1] + 1;
            plate[i] = plate[i + 1] - 1;
        }
    }

    cout << result << endl;
    return 0;
}