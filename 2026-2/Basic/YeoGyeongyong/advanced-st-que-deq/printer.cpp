#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_num;

  cin >> test_num;



  for (int i = 0; i < test_num; i++) {
    int n, m;
    int cnt = 0;

    queue<pair<int, int>> q;
    
    cin >> n >> m;

    for (int j = 0; j < n; j++) {
      int weight;

      cin >> weight;

      pair<int, int> p(weight, j);

      q.push(p);
    }

    int max = -1;

    while(true) {
      max = -1;

      for (int j = 0; j < (int)q.size(); j++) {
        if (max < q.front().first) {
          max = q.front().first;
        }

        q.push(q.front());
        q.pop();
      }

      if(q.front().first < max) {
        q.push(q.front());
        q.pop();

        continue;
      }

      if(max == q.front().first && q.front().second == m) {
        cnt++;

        break;
      }

      q.pop();

      cnt++;
    }

    cout << cnt << "\n";
  }

  return 0;
}
