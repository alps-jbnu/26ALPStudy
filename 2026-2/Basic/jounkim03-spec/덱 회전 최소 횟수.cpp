#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
    cin >> n >> m;
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
    	int x;
    	cin>>x;
    	int idx = 0;
    	for(int j = 0 ; j < dq.size(); j++){
    		if(dq[j] == x){
    			idx = j;
    			break;
			}
		}
		if(dq.front() == x){
			dq.pop_front();
		}
		else{
			if(idx <= dq.size()/2){
				while(dq.front() != x){
					dq.push_back(dq.front());
					dq.pop_front();
					ans++;
				}
			}
			else{
				while(dq.front() != x){
					dq.push_front(dq.back());
					dq.pop_back();
					ans++;
				}
			}
			dq.pop_front();
		}
	}
	cout<<ans;
	return 0;
}