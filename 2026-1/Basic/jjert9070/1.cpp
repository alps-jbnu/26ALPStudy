#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned int func1(unsigned int n);
int main()
{
	int n;
	cin >> n;

	cout << func1(n) << endl;

	return 0;

}

unsigned int func1(unsigned int n)
{
	int i;
	unsigned int result = 0;

	for (i=1; i<=n;i++) // n
	{
		if ((i % 3 == 0) || (i % 5 == 0))
			result += i;
	} // n * (2 + 1) = 3n

	return result;

} // 시간복잡도 O(n)