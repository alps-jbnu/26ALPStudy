#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> m >> n;
    int stick[1000000];
    int max_h = 0;
    for(int i = 0; i < n; i++) {
        cin >> stick[i];
        max_h = max(max_h, stick[i]);
    }
    int st = 1, en = max_h;
    int ans = 0;
    while(st <= en) {
        int avail_stick = 0;
        int mid = (st + en) / 2;
        for(int i = 0; i < n; i++) {
            int cur_stick = stick[i];
            while(cur_stick >= mid) {
                avail_stick++;
                cur_stick -= mid;
            }
        }
        if(avail_stick >= m) {
            st = mid + 1;
            ans = mid;
        }
        else {
            en = mid - 1;
        }
    }
    cout << ans << "\n";
}