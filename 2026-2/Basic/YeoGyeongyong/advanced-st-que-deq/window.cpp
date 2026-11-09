#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;

    cin >> n >> l;

    deque<pair<int, int>> dq;

    for (int i = 0; i < n; i++) {
      int a;

      cin >> a;

      pair<int, int> p(a, i);

      while(!dq.empty() && dq.front().second < i - l + 1) {
        dq.pop_front();
      }

      while(!dq.empty() && dq.back().first >= a) {
        dq.pop_back();
      }

      dq.push_back(p);

      cout << dq.front().first << " ";
    }
    
    return 0;
}
