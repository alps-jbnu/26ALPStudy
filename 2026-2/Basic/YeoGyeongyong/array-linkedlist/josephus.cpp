#include <bits/stdc++.h>
#include <list>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;

  cin >> n >> k;

  list<int> l;

  for (int i = 1; i <= n; i++) {
    l.push_back(i);
  }

  auto it = l.begin();

  cout << '<';

  while (!l.empty()) {
    for (int i = 0; i < k - 1; i++) {
      ++it;
      if (it == l.end()) {
        it = l.begin();
      }
    }
    if (l.size() == 1) {
      cout << *it;
    } else {
      cout << *it << ", ";
    }
    it = l.erase(it);
    if (it == l.end()) {
      it = l.begin();
    }
  }

  cout << '>';

  return 0;
}
