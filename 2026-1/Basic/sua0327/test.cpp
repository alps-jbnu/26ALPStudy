#include <iostream>
using namespace std;
int main(void) {
	int year;
	cin >> year;
	if (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0)) {
		cout << "Leap Year" << endl;

	}
	else
	{
		cout << "Not a Leap Year" << endl;
	}
	return 0;



}