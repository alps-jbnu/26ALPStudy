#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string fw;
    string sw;

    cin >> fw;
    cin >> sw;

    int fw_cnt[26] = {};
    int sw_cnt[26] = {};

    for (char c : fw) {
      int idx = c - 'a';

      fw_cnt[idx]++;
    }

    for (char c : sw) {
      int idx = c - 'a';

      sw_cnt[idx]++;
    }

    int answer = 0;

    for (int i = 0; i < 26; i++) {
      answer += abs(fw_cnt[i] - sw_cnt[i]);
    }

    cout << answer;

    return 0;
}
