#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    stack<int> s;
    int result = 0;

    cin >> k;

    for (int i = 0; i < k; i++) {
      int num;

      cin >> num;

      if (num == 0) {
        s.pop();
      } else {
        s.push(num);
      }
    }

    while (!s.empty()) {
      result += s.top();
      s.pop();
    }

    cout << result;
    
    return 0;
}
