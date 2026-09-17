#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int max_len = 0;
    int cur_len = 0;
    int cur_k = k;
    int left = 0, right = 0;
    while (right < n) {
        if (arr[right] % 2 == 0) {
            cur_len++;
        } else {
            if(cur_k > 0){
                cur_k--;
            }
            else{
                while (arr[left] % 2 == 0) {
                    cur_len--;
                    left++;
                }
                left++;
            }
        }
        max_len = max(max_len, cur_len);
        right++;
    }
    cout << max_len << "\n";
    return 0;
}