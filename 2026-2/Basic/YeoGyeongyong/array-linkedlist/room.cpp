#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    int arr[9] = {};

    cin >> n;

    while (n > 0) {
      int idx = n%10;
  
      if (idx == 9) {
        idx = 6;
      }

      arr[idx]++;

      n /= 10;
    }

    arr[6] = (arr[6] + 1) / 2;

    int max = 0;

    for (int i = 0; i < 9; i++) {
      if (max < arr[i]) {
        max = arr[i];
      }
    }

    cout << max;

    return 0;
}
