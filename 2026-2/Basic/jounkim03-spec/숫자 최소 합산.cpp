#include <bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin>>k;
	int x,ans = 0;
	vector<int> arr;
	for(int i = 0 ; i < k ; i++){
		cin>>x;
		if(x == 0){
			arr.pop_back();
		}
		else{
			arr.push_back(x);
		}
	}
	for(int i = 0; i < arr.size(); i++){
		ans += arr[i];
	}
	cout<<ans; 
	return 0;
}