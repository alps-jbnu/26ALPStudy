#include <iostream>

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	unsigned long long int data_1, data_2;
	unsigned long long int range = 0;
	unsigned long long int i;
	cin >> data_1 >> data_2;

	if (data_1 == data_2)
		range = 0;
	else if (data_1 > data_2)
		range = data_1 - data_2 - 1;
	else if (data_1 < data_2)
		range = data_2 - data_1 - 1;

	cout << range << '\n';

	if (data_1 > data_2)
		for (i = 1; data_2 + i < data_1; i++)
			cout << data_2 + i << ' ';
	else if (data_1 < data_2)
		for (i = 1; data_1 + i < data_2; i++)
			cout << data_1 + i << ' ';
	
	return 0;
}