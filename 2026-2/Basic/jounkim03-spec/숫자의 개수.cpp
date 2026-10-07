#include <iostream>
using namespace std;
int main(){
	int a,b,c;
	int count[10] = {0};
	cin>>a>>b>>c;
	int mul = 0,d = 0;
	mul = a*b*c;
	for( d = 0; mul != 0; d++){
		count[mul%10]++;
		mul /= 10;
	}
	for(int i = 0 ; i < 10; i++){
		cout<<count[i]<<'\n';
	}
	return 0;
}