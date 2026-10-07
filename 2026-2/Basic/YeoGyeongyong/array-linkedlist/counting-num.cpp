#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> arr(n);
    int v;

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    cin >> v;

    int cnt = 0;

    for (int i = 0; i < n; i++) {
      if (arr[i] == v) {
        cnt++;
      }
    }

    cout << cnt;
    
    return 0;
}
