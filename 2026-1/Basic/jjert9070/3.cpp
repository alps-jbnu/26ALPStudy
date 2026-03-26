#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int func3(int N);

int main()
{
	cout << func3(9) << endl;
	cout << func3(693953651) << endl;
	cout << func3(756580036) << endl;

	return 0;
}
//
//int func3(int N)
//{
//	int i;
//
//	// 0, 1, 2, 3, 4..........N
//	for (i = 0; i < N; i++)
//	{
//		// 1 * 1, 2 * 2, 3 * 3, 4 * 4 .... N * N
//		if (((i + 1) * (i + 1)) == N)
//			return 1;
//	}
//	// N*3 O(N)
//	// 총 횟수 (루트N) * 3 O(루트N)
//	return 0;
//}

int func3(int N)
{
	int i;
	int result;
	// 루트N * 7 O(루트N)
	for (i = 0; (result = (i + 1) * (i + 1)) <= N; i++)
		if (result == N)
			return 1;

	return 0;

}