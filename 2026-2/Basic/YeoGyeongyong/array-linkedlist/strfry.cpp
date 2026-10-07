#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
      string s1;
      string s2;

      int s1_arr[26] = {};
      int s2_arr[26] = {};

      cin >> s1 >> s2;

      for (char c : s1) {
        s1_arr[c - 'a']++;
      }
      for (char c : s2) {
        s2_arr[c - 'a']++;
      }

      if (equal(s1_arr, s1_arr + 26, s2_arr)) {
        cout << "Possible" << "\n";
      } else {
        cout << "Impossible" << "\n";
      }
    }
    
    return 0;
}
