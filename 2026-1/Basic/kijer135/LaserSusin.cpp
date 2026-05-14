#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	int count;

	vector<int> indexes;

	vector<int> results;

	cin >> count;

	for (size_t i = 0; i < count; i++)
	{
		int temp;
		cin >> temp;
		indexes.push_back(temp);
	}

	int k = 0;

	for (size_t i = 0; i < count; i++)
	{
		k = i;
		while (k >= 0)
		{
			if (indexes[k] > indexes[i])
			{
				break;
			}
			k--;
		}
		results.push_back(k + 1);
	}

	for (size_t i = 0; i < count; i++)
	{
		cout << results[i] << " ";
	}	

}