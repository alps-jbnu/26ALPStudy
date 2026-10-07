#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n,d;
	vector<int> arr(10,0);
	cin >> n;
	int r = n;
	for(d = 0; n != 0; d++ ){
		arr[n%10]++;
		n /= 10;
	}
	arr[6] = (arr[6]+arr[9]+1)/2;
	int max = arr[0];
	for(int i = 1; i < 9; i ++){
		if( max < arr[i]){
			max = arr[i];
		}
	}
	if( r == 0){
		max = 1;
	}
	cout<<max;
	return 0;
}