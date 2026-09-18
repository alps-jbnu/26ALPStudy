#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> m >> n;
    pair<int, int> arr[m][n];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j].first;
            arr[i][j].second = j;
        }
    }
    for(int i = 0; i < m; i++) {
        sort(arr[i], arr[i] + n, [](pair<int, int> a, pair<int, int> b){
            return a.first < b.first;
        });
    }
    int pre, cnt;
    for(int i = 0; i < m; i++){
        pre = arr[i][0].first;
        cnt = 0;
        for(int j = 0; j < n; j++){
            if(arr[i][j].first != pre) 
                cnt++;
                pre = arr[i][j].first;
                arr[i][j].first = cnt;
        }
    }
    for(int i = 0; i < m; i++){
        sort(arr[i], arr[i] + n, [](pair<int, int> a, pair<int, int> b){
            return a.second < b.second;
        });
    }
    int ans = 0;
    for(int i = 0; i < m - 1; i++){
        for(int ii = i + 1; ii < m; ii++){
            bool same = true;
            for(int j = 0; j < n; j++){
                if(arr[i][j].first != arr[ii][j].first){
                    same = false;
                    break;
                }
            }
            if(same) ans++;
        }
    }
    cout << ans << "\n";
}