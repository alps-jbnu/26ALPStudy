#include <iostream>
using namespace std;


int main()
{
	int num = 0;

	cin >> num;

	for (size_t i = 1; i <= num; i++)
	{
		for (size_t k = 0; k < i - 1; k++) cout << " ";
		for (size_t j = 0; j < 2 * num - (i * 2 - 1); j++) cout << "*";
		cout << "\n";
	}

	for (size_t i = 2; i <= num-1; i++)
	{
		for (size_t k = 0; k < num - i; k++) cout << " ";
		for (size_t j = 0; j < 2 * i - 1; j++) cout << "*";
		cout << "\n";
	}
    
	if (num > 1) for (size_t i = 0; i < 2 * num - 1; i++) cout << "*";
}