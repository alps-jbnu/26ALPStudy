#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long cnt = 0;

    stack<int> s;

    cin >> n;

    for(int i = 0; i < n; i++) {
      int hi;

      cin >> hi;

      while(!s.empty() && s.top() <= hi) {
        s.pop();
      }

      cnt += s.size();

      s.push(hi);
    }

    cout << cnt;
    
    return 0;
}
