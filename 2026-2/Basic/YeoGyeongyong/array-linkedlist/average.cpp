#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d, e;
    
    cin >> a >> b >> c >> d >> e;

    int avg = (a + b + c + d + e) / 5;

    int arr[5] = { a, b, c, d, e };

    sort(arr, arr+5);

    cout << avg << "\n" << arr[2];

    return 0;
}
