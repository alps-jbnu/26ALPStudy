//
// Created by 손민균 on 26. 10. 5.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int last_minus_index = -1;
    int last_zero_index = -1;
    int last_one_index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) last_minus_index = i;
        if (arr[i] == 0) last_zero_index = i;
        if (arr[i] == 1) last_one_index = i;
    }

    int total = 0;
    if (last_minus_index == -1) {
        int buffer = 0;
        int buffer_cum = 0;
        for (int i = n - 1; i > ((last_one_index != -1)?last_one_index:last_zero_index); i--) {
            if (buffer == 0) {
                buffer = arr[i];
                buffer_cum = 1;
            }
            else if (buffer == arr[i]) buffer_cum += 1;
            else {
                total += arr[i] * buffer;
                buffer_cum--;
                if (buffer_cum == 0) buffer = 0;
            }
        }
        total += buffer * buffer_cum;
        if (last_one_index != -1) total += last_one_index - last_zero_index;
    }
    else {
        int buffer = 0;
        int buffer_cum = 0;
        for (int i = 0; i <= last_minus_index; i++) {
            if (buffer == 0) {
                buffer = arr[i];
                buffer_cum = 1;
            }
            else if (buffer == arr[i]) buffer_cum += 1;
            else {
                total += arr[i] * buffer;
                buffer_cum--;
                if (buffer_cum == 0) buffer = 0;
            }
        }

        if (last_zero_index != -1) {
            buffer_cum -= last_zero_index - last_minus_index;
        }
        if (buffer_cum > 0) total += buffer_cum * buffer;
        buffer = 0;
        buffer_cum = 0;

        int boundary = 0;
        if (last_one_index != -1) boundary = last_one_index;
        else if (last_zero_index != -1) boundary = last_zero_index;
        else boundary = last_minus_index;
        for (int i = n - 1; i > boundary; i--) {
            if (buffer == 0) {
                buffer = arr[i];
                buffer_cum = 1;
            }
            else if (buffer == arr[i]) buffer_cum += 1;
            else {
                total += arr[i] * buffer;
                buffer_cum--;
                if (buffer_cum == 0) buffer = 0;
            }
        }
        total += buffer * buffer_cum;

        if (last_one_index != -1) {
            if (last_zero_index != -1) boundary = last_zero_index;
            else boundary = last_minus_index;
            total += last_one_index - boundary;
        }
    }
    cout << total << endl;
    return 0;
}