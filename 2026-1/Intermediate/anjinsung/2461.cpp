#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int start = 0;
    int end = n-1;
    int min_diff = 2147483647; // 합의 최댓값(약 20억)보다 큰 값으로 설정
    int ans_start = 0, ans_end = 0;

    while(start < end){
        int sum = v[start] + v[end];
        
        if(abs(sum) < min_diff){
            min_diff = abs(sum);
            ans_start = v[start];
            ans_end = v[end];
        }
        
        if(sum < 0) start++;
        else if(sum > 0) end--;
        else break; // 합이 정확히 0이면 더 이상 탐색할 필요 없음
     }
    
    cout << ans_start << " " << ans_end;
    return 0;
}