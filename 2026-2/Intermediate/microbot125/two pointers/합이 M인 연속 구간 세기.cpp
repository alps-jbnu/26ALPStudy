//
// Created by 손민균 on 26. 9. 14.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int start = 0;
    int end = 1;
    int sum = arr[0];
    int total_pair = 0;

    while (true) {
        if (sum > m && start + 1 == end && end == n) break;
        else if (sum > m && end == n) {
            sum -= arr[start];
            start++;
        }
        else if (sum > m && start + 1 == end) {
            sum += arr[end];
            sum -= arr[start];
            start++;
            end++;
        }
        else if (sum > m) {
            sum -= arr[start];
            start++;
        }
        else if (sum == m && end == n) {
            total_pair++;
            break;
        }
        else if (sum == m) {
            total_pair++;
            sum += arr[end];
            sum -= arr[start];
            start++;
            end++;
        }
        else if (sum < m && end == n) break;
        else if (sum < m) {
            sum += arr[end];
            end++;
        }
    }
    cout << total_pair;
    return 0;
}