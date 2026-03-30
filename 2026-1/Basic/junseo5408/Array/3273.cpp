#include <bits/stdc++.h>
using namespace std;
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    fastIO();
    int n, x, target;
    int cnt = 0;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];  
    }
    cin>>x;
    sort(v.begin(), v.end());
    int left = 0, right = n-1;
    while(left<right){
        int sum = v[left]+v[right];
        if(sum==x){
            cnt++;
            left++;
            right = n-1;
        }
        else if(sum>x){
            right--;
        }
        else{
            left++;
            right = n-1;
        }
    }
    cout<<cnt<<"\n";
}