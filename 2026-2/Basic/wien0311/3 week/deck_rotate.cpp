#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    deque<int> d;
    int n, m, idx1, idx2, k, sum;
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        d.insert(d.begin()+i, i+1);
    }

    for(int i=0; i<m; i++) { //찾아야 하는 원소의 수만큼 반복
        cin>>k;
        auto it = find(d.begin(), d.end(), k);
        idx1 = it - d.begin(); //[0]에서 부터
        idx2 = d.end() - it; //끝에서 부터
        
        if(idx1 <= idx2) {
            for(int j=0; j<idx1; j++) {
                d.push_back(d.front());
                d.pop_front();
                sum+=1;
            }
        }

        else if(idx1 > idx2) {
            for(int j=0; j<idx2; j++) {
                d.push_front(d.back());
                d.pop_back();
                sum+=1;
            }
        }

        d.pop_front();
    }
    cout<<sum<<"\n";


    return 0;
}//뭔가 잘못됌