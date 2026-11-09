//
// Created by 손민균 on 26. 9. 12.
//
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> woods(n);
    for (int i = 0; i < n; i++) {
        cin >> woods[i];
    }

    sort(woods.begin(), woods.end());
    stack< pair<int, int> > s;
    s.emplace(0, 0);
    s.emplace(0, 0);

    int current_wood_height = woods[0];
    int current_wood_sequence = 1;
    for (int i = 1; i < n; i++) {
        if ( woods[i] == current_wood_height ) {
            current_wood_sequence++;
        }
        else {
            s.emplace(current_wood_height, current_wood_sequence);
            current_wood_height = woods[i];
            current_wood_sequence = 1;
        }
    }
    s.emplace(current_wood_height, current_wood_sequence);

    int sum_wood = 0;
    pair<int, int> wood_block = s.top();
    s.pop();
    pair<int, int> next_block = s.top();
    next_block.second += wood_block.second;

    while (sum_wood < m) {
        if ((wood_block.first - next_block.first)*wood_block.second + sum_wood <= m) {
            sum_wood += (wood_block.first - next_block.first)*wood_block.second;
            wood_block = next_block;
            s.pop();
            next_block = s.top();
            next_block.second += wood_block.second;
            if (sum_wood >= m) cout << wood_block.first << endl;
        }
        else {
            int need_wood_height = (m - sum_wood) / wood_block.second + ((m - sum_wood) % wood_block.second == 0?0:1);
            sum_wood  += need_wood_height * wood_block.second;
            cout << wood_block.first - need_wood_height << endl;
        }
    }

    return 0;
}