#include <iostream>
#include <utility>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	unsigned int A, B;

	cin >> A >> B;

	if(A > B) swap(A, B);

	cout << ((A == B) ? 0 : (B - A - 1)) << '\n';

	for(int i = A + 1; i < B; i++) {
		cout << i << ' ';
	}

	cout << '\n';

}
