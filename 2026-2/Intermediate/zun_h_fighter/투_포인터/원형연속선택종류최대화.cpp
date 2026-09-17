#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> dishes(n);
    for(int i = 0; i < n; i++) {
        cin >> dishes[i];
    }
    int left = 0, right = k - 1, unique_cnt = 1;
    vector<int> count(d + 1, 0);
    count[c] = 1;
    for(int i = 0; i < k; i++) {
        count[dishes[i]]++;
        if(count[dishes[i]] == 1) {
            unique_cnt++;
        }
    }
    int ans = unique_cnt;
    while(left < n + k - 1){
        count[dishes[left%n]]--;
        if(count[dishes[left%n]] == 0) {
            unique_cnt--;
        }
        left++;
        right++;
        count[dishes[right%n]]++;
        if(count[dishes[right%n]] == 1) {
            unique_cnt++;
        }
        ans = max(ans, unique_cnt);
    }
    cout << ans << "\n";
    return 0;
}