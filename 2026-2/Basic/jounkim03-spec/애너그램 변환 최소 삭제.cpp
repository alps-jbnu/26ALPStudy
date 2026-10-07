#include <iostream>
#include <cmath>
using namespace std;
int main(){
	string a,b;
	int counta[26] = {0}, countb[26] = {0},ans = 0;
	cin>>a>>b;
	for(int i = 0 ; i < a.length(); i ++){
		counta[a[i]-'a']++;
	}
	for(int i = 0 ; i < b.length(); i ++){
		countb[b[i]-'a']++;
	}
	for(int i = 0; i < 26; i ++){
		if(counta[i] != countb[i]){
			ans += abs(counta[i]-countb[i]);
		}
	}
	cout<<ans;
	return 0;
}