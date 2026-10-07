//
// Created by 손민균 on 26. 9. 28.
//
#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    result[0] = arr[0];

    for (int i = 1; i < n; i++) {
        int max = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && result[j] > max) {
                max = result[j];
            }
        }
        result[i] = max + arr[i];
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < result[i]) max = result[i];
    }

    cout << max << endl;

    return 0;
}

