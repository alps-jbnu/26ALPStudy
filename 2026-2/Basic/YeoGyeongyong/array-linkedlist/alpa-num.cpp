#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int arr[26] = {};

    cin >> s;

    for (char c : s) {
      arr[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
      cout << arr[i] << " ";
    }
    
    return 0;
}
