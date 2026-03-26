#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> s(n+1);
    for (int i = 1; i < n+1; i++) {
        cin >> s[i];
    }
    
    int left = 1;
    int odd_count = 0;
    int max_len = 0;

    for (int right = 1; right <= n; right++) {
        if (s[right] % 2 != 0) {
            odd_count++;
        }

        while (odd_count > k) {
            if (s[left] % 2 != 0) {
                odd_count--;
            }
            left++;
        }

        max_len = max(max_len, right - left + 1 - odd_count);
    }

    cout << max_len << "\n";
    return 0;
} 