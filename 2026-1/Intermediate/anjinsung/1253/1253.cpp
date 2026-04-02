#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {       
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        vector<int> tmp = v;
        tmp.erase(tmp.begin()+i);
        int start = 0;
        int end = 0;
        if(i == n-1){
            end = n-2;
        } else{
            end = n-1;
        }
        while(start < end){
            if(tmp[start] + tmp[end] == v[i]){
                ans++;
                break;
            }
            else if(tmp[start] + tmp[end] < v[i]){
                start++;
            }
            else{
                end--;
            }
        }
    }

    cout << ans;
    
    return 0;
}