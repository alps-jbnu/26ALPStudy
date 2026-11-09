//
// Created by 손민균 on 26. 9. 14.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> belt(n);
    for (int i = 0; i < n; i++) {
        cin >> belt[i];
        belt[i]--;
    }
    c--;
    vector<int> eat_dish(d);
    int start = 0;
    int end = k;
    int maximum_combination = 0;
    int current_combination = 0;
    for (int i = start; i < end; i++) {
        if (eat_dish[belt[i]] == 0) current_combination++;
        eat_dish[belt[i]]++;
    }
    if (eat_dish[c] == 0) maximum_combination = current_combination + 1;
    else maximum_combination = current_combination;
    for (int i = 0; i < n - 1; i++) {
        if (--eat_dish[belt[start]] == 0) current_combination--;
        if (start == n - 1) start = 0;
        else start++;
        if (eat_dish[belt[end]]++ == 0) current_combination++;
        if (end == n - 1) end = 0;
        else end++;
        if (maximum_combination < current_combination + (eat_dish[c] == 0)?1:0) maximum_combination = current_combination + ((eat_dish[c] == 0)?1:0);
    }
    cout << maximum_combination << endl;
}