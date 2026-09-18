#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> sum(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i == 0) sum[i] = a[i];
        else sum[i] = sum[i-1] + a[i];
    }
    int ans = 0;
    int l = 0, r = 0;
    while(l < n && r < n){
        int temp;
        if(l == 0) temp = sum[r];
        else temp = sum[r] - sum[l-1];
        if(temp == m) ans++;
        if(temp < m) r++;
        else l++;
    }
    cout << ans;
    return 0;
}