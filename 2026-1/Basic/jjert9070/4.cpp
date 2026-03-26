#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

int func4(int N);

int main()
{
	cout << func4(5) << endl;
	cout << func4(97615282) << endl;
	cout << func4(1024) << endl;
}
//
//int func4(int N)
//{
//	int result = 1;
//	while (result <= N)
//	{// N회 반복
//		result *= 2;
//		if (result > N)
//		{
//			result = result / 2;
//			break;
//		}
//
//	}// O(log2N)
//	
//
//	return result;
//}


int func4(int N)
{
	int val = 1;
	while (2 * val <= N) val *= 2;
	return val;
} //O(lgN)



