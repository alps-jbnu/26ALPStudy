#if 0
#include <iostream>

unsigned long long mul(unsigned long long ret, unsigned long long count, unsigned long long divisor)
{
	unsigned long long result;
	if (count == 1)
	{
		return ret % divisor;
	}

	if (count % 2 == 0)
	{
		result = mul(ret, count / 2, divisor);
		return (result * result) % divisor;
	}

	if (count % 2 == 1)
	{
		unsigned long long left = mul(ret, count - 1, divisor);
		unsigned long long right = mul(ret, 1, divisor);
		return (left  * right) % divisor;
	}

}

int main()
{
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	unsigned long long input1, input2, input3;

	std::cin >> input1 >> input2 >> input3;
	std::cout << mul(input1, input2, input3) << '\n';


	return 0;
}
#endif