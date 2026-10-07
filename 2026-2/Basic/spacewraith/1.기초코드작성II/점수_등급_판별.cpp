#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;

	if(T >= 90) {
		cout << 'A';
	} else if(T <= 89 && T >= 80) {
		cout << 'B';
	} else if(T <= 79 && T >= 70) {
		cout << 'C';
	} else if(T <= 69 && T >= 60) {
		cout << 'D';
	} else { 
		cout << 'F';
	}

}
