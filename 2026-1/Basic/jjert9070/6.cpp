#include <iostream>
#include <vector>
using namespace std;

bool cmp1(vector<int> v1, vector<int> v2, int idx);
bool cmp2(vector<int>& v1, vector<int>& v2, int idx);
void func1(vector<int> v);
void bufferfunc();

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v(100);
	// func1(v);
	bufferfunc();
	cout << v[10];
}

bool cmp1(vector<int> v1, vector<int> v2, int idx)
{
	// 시간복잡도는 O(N)
	// 그 이유는 N개의 원소를 일일히 복사함
	return v1[idx] > v2[idx];
}

bool cmp2(vector<int>& v1, vector<int>& v2, int idx)
{
	// 참조자를 사용해서 접근
	// O(1)
	return v1[idx] > v2[idx];
}

void func1(vector<int> v)
{
	// vector<int> v는 복사만 수행함
	v[10] = 7;
}

void bufferfunc()
{
	// endl 쓰지 마세요.

	for (int i = 0; i < 3; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << a + b << '\n';
	}
}


