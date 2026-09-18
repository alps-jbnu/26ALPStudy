#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, K;

	cin >> N >> K;

	vector<int> seats;
	for(int i = 1; i <= N; i++){
		seats.push_back(i);
	}

	int idx = 0;

	cout << '<';

	while(!seats.empty()) {
		idx = (idx + K - 1) % seats.size();

		cout << seats[idx];
		seats.erase(seats.begin() + idx);

		if(!seats.empty())  
			cout << ", ";
	}

	cout << '>';
}
