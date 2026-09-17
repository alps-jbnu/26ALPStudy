#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int tree[1000000];
    int max_h = 0;
    for(int i = 0; i < n; i++) {
        cin >> tree[i];
        max_h = max(max_h, tree[i]);
    }
    int st = 1, en = max_h;
    int ans = 0;
    while(st <= en) {
        long long sum = 0;
        int mid = (st + en) / 2;
        for(int i = 0; i < n; i++) {
            if(tree[i] > mid)
                sum += (tree[i] - mid);
        }
        if(sum >= m) {
            st = mid + 1;
            ans = mid;
        }
        else {
            en = mid - 1;
        }
    }
    cout << ans << "\n";
}