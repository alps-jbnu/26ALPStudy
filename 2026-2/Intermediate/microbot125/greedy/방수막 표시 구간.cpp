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
    vector< pair<int, int> > work(n);
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        work[i].first = start;
        work[i].second = end;
    }
    sort(work.begin(), work.end());

    vector< pair<int, int> > result;
    pair<int, int> temp = work[0];
    for (int i = 1; i < n; i++) {
        if (temp.second < work[i].first) {
            result.push_back(temp);
            temp = work[i];
        }
        else {
            if (temp.second < work[i].second) temp.second = work[i].second;
        }
    }
    result.push_back(temp);
    int length = 0;
    for (pair<int, int> & i : result) {
        length += i.second - i.first;
    }

    cout << length << endl;

    return 0;
}