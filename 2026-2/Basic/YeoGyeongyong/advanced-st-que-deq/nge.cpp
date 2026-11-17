#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    stack<pair<int, int>> s;
    vector<int> answer(n, -1);


    for(int i = 0; i < n; i++) {
      int element;

      cin >> element;

      pair<int, int> k(element, i);

      while(!s.empty() && k.first > s.top().first) {
        answer[s.top().second] = k.first;

        s.pop();
      }

      s.push(k);
    }

    for (int i = 0; i < n; i++) {
      cout << answer[i] << " ";
    }
    
    return 0;
}
