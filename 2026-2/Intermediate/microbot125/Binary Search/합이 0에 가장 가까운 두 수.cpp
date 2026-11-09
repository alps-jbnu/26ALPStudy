//
// Created by 손민균 on 26. 9. 12.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int abs_sum(int a, int b) {
    if (a + b > 0) return a + b;
    else return -a - b;
}

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    int front_index = 0;
    int back_index = vec.size() - 1;
    int min = abs_sum(vec[front_index], vec[back_index]);
    int minimum_front = vec[front_index];
    int minimum_rear = vec[back_index];

    while (true) {
        if (abs_sum(vec[front_index + 1],vec[back_index]) > abs_sum(vec[front_index],vec[back_index - 1])) {
            back_index--;
        }
        else {
            front_index++;
        }
        if (front_index >= back_index) break;
        if (abs_sum(vec[front_index], vec[back_index]) < min) {
            min = abs_sum(vec[front_index] , vec[back_index]);
            minimum_front = vec[front_index];
            minimum_rear = vec[back_index];
        }
    }

    cout << minimum_front << ' ' << minimum_rear << endl;
    return 0;
}