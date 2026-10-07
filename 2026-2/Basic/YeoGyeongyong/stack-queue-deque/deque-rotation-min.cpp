#include <bits/stdc++.h>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> dq;
    int n, m;
    int count = 0;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
      dq.push_back(i);
    }

    for (int i = 0; i < m; i++) {
      int pop_num;

      cin >> pop_num;

      auto it = find(dq.begin(), dq.end(), pop_num);

      int idx = it - dq.begin();

      int rot_num;

      if (idx <= dq.size() - idx) {
        rot_num = idx;
        for (int i = 0; i < rot_num; i++) {
          dq.push_back(dq.front());
          dq.pop_front();
          count++;
        }
        dq.pop_front();
      } else {
        rot_num = dq.size() - idx;
        for (int i = 0; i < rot_num; i++) {
          dq.push_front(dq.back());
          dq.pop_back();
          count++;
        }
        dq.pop_front();
      }
    }

    cout << count;

    return 0;
}
