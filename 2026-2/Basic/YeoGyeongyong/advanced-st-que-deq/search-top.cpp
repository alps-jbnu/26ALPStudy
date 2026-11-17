#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    stack<pair<int, int>> s;

    cin >> n;

    for(int i = 0; i < n; i++) {
      int number;

      cin >> number;

      pair<int, int> k(number, i + 1);

      if (s.empty()) {
        s.push(k);

        cout << 0 << " ";

        continue;
      }

      while(s.top().first < number) {
        s.pop();

        if(s.empty()) {  
          break;
        }
      }

      if(s.empty()) {
        s.push(k);

        cout << 0 << " ";

        continue;
      }

      cout << s.top().second << " ";

      s.push(k);
    }


    
    return 0;
}
