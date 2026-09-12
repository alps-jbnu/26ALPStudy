//
// Created by 손민균 on 26. 9. 12.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a_num, b_num;
    cin >> a_num >> b_num;

    vector<int> a(a_num);
    vector<int> b(b_num);

    for (int i = 0; i < a_num; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < b_num; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int a_index = 0;
    int b_index = 0;
    int remain = a_num;
    while(a_index != a_num && b_index != b_num) {
        if (a[a_index] > b[b_index]) {
            b_index++;
        }
        else if (a[a_index] < b[b_index]) {
            a_index++;
        }
        else if (a[a_index] == b[b_index]) {
            a[a_index] = 0;
            remain--;
            a_index++;
            b_index++;
        }
    }

    cout << remain << endl;
    for (int i = 0; i < a_num; i++) {
        if (a[i] != 0) {
            cout << a[i] << " ";
        }
    }
    return 0;
}