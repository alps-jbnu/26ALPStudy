#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void func1();
void func2();
void func3();

int main()
{
	func1();
	func2();
	func3();

	return 0;
}


void func1()
{
	for (char s = 0; s < 128; s++)
		cout << "hi";
}

void func2()
{
	int r = 1;
	for (int i = 0; i <= 50; i++)
		r = r * i % 6;

	return r;
}

void func3()
{
	int a = 10;
	int mod = 1000000007;
	for (int i = 0; i < 10; i++)
		a = 10 * a % mod;
	return a;
}

