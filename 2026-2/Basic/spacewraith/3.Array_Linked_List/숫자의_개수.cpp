#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, C;
	int product;
	int count[10] = {0, };

	cin >> A >> B >> C;
	product = A * B * C;

	do {
		count[product % 10]++;
		product /= 10;
	} while(product != 0);


	for(int i : count) {
		cout << i << '\n';
	}
		
}
