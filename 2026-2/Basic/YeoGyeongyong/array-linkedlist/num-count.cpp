#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;

    cin >> a >> b >> c;

    int mult_num = a * b * c;

    int answer[10] = {};

    while (mult_num > 0) {
      answer[mult_num % 10]++;

      mult_num /= 10;
    }

    for (int i = 0; i < 10; i++) {
      cout << answer[i] << "\n";
    }

    return 0;
}
