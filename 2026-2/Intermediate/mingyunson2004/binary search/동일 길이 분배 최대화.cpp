//
// Created by 손민균 on 26. 9. 13.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binary_search_for_target_or_less(vector<int> &vec, int target, int start, int end, long long l) {
    if (vec[end] / l <= target) return end;
    if (start + 1 == end) {
        return start;
    }
    if (vec[(start + end) / 2] / l <= target) {
        return binary_search_for_target_or_less(vec, target, (start + end) / 2, end, l);
    }
    else {
        return binary_search_for_target_or_less(vec, target, start, (start + end) / 2, l);
    }
}

bool can_be_distributed_sticks_of_length_l(int m, long long l, vector<int>& sticks) {
    int scale = sticks[0] / l;
    long long number_of_length_l_sticks = 0;
    int start = 0;
    int end = sticks.size() - 1;
    while (true) {
        int scale_boundary_index = binary_search_for_target_or_less(sticks, scale, start, end, l);
        number_of_length_l_sticks += (scale_boundary_index - start + 1) * scale;
        if (scale_boundary_index == end) break;
        else {
            start = scale_boundary_index + 1;
            scale = sticks[start] / l;
        }
    }
    return number_of_length_l_sticks >= m;
}

int main() {
    int m, n;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;

    vector<int> stick(n);
    long long sum_of_stick_length = 0;
    for (int i = 0; i < n; i++) {
        cin >> stick[i];
        sum_of_stick_length += stick[i];
    }

    sort(stick.begin(), stick.end());

    long long max_divided_stick_length_if_can_connet_stick = sum_of_stick_length / m;
    if (max_divided_stick_length_if_can_connet_stick == 0) cout << 0 << endl;
    else {
        long long minimum = 1;
        long long maximum = max_divided_stick_length_if_can_connet_stick;
        if (can_be_distributed_sticks_of_length_l(m, maximum, stick)) {
            cout << maximum << endl;
        }
        else {
            while (true) {
                if (can_be_distributed_sticks_of_length_l(m, (maximum + minimum)/2, stick)) {
                    minimum = (maximum + minimum) / 2;
                }
                else {
                    maximum = (maximum + minimum) / 2;
                }
                if (maximum == minimum + 1) {
                    cout << minimum << endl;
                    break;
                }
            }
        }
    }

    return 0;
}