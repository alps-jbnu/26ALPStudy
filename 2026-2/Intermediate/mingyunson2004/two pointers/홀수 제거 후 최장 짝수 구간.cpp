//
// Created by 손민균 on 26. 9. 14.
//
#include <iostream>
#include <istream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    int sequence = 0;
    int odd_num = 0;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if (input % 2 == 1) {
            arr.push_back(sequence);
            sequence = 0;
            odd_num++;
        }
        else sequence++;
    }
    arr.push_back(sequence);
    if (odd_num < k) k = odd_num;
    int start = 0;
    int total = 0;
    for (int i = start; i < k + 1; i++) {
        total += arr[i];
    }
    int max = total;
    for (int i = k + 1; i < arr.size(); i++) {
        total -= arr[start];
        start++;
        total += arr[i];
        if (max < total) max = total;
    }
    cout << max << endl;
}