#include <bits/stdc++.h>
#include <list>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;

    list<char> log;
    auto cursor = log.begin();

    cin >> s;

    for (char c : s) {
      if (c == '<') {
        if (cursor == log.begin()) {
          continue;
        }

        --cursor;
      } else if (c == '>') {
        if (cursor == log.end()) {
          continue;
        }

        ++cursor;
      } else if (c == '-') {
        if (cursor == log.begin()) {
          continue;
        }

        --cursor;
        cursor = log.erase(cursor);
      } else {
        log.insert(cursor, c);
      }      
    }

    for (char k : log) {
      cout << k;
    }

    cout << "\n";
  }

  return 0;
}
