//
// Created by 손민균 on 26. 9. 28.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max = arr[0];
    int sum = arr[0];
    int end = 0;
    while (end < n - 1) {
        if (sum >= 0) {
            end++;
            sum += arr[end];
        }
        else {
            end++;
            sum = arr[end];
        }
        if (sum > max) {
            max = sum;
        }
    }

    cout << max << endl;
    return 0;
}