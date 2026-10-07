#include <bits/stdc++.h>
#include <list>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string fs;
  int n;
  list<char> s;

  cin >> fs;
  cin >> n;

  for (char c : fs) {
    s.push_back(c);
  }

  auto cursor = s.end();

  for (int i = 0; i < n; i++) {
    char cmd;

    cin >> cmd;

    if (cmd == 'L') {
      if (cursor == s.begin()) {
        continue;
      } else {
        --cursor;
      }
    }

    if (cmd == 'D') {
      if (cursor == s.end()) {
        continue;
      } else {
        ++cursor;
      }
    }

    if (cmd == 'B') {
      if (cursor == s.begin()) {
        continue;
      } else {
        --cursor;
        cursor = s.erase(cursor);
      }
    }

    if (cmd == 'P') {
      char new_c;

      cin >> new_c;

      s.insert(cursor, new_c);
    }
  }
  
  for (char c : s) {
    cout << c;
  }

  return 0;
}
