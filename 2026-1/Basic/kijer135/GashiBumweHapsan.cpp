#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	int count = 0;

    int result = 0;

    cin >> count;

    vector<int> indexes;

    for (int i = 0; i < count; i++)
    {
        int temp;
        cin >> temp;
        indexes.push_back(temp);
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (indexes[i] > indexes[j])
            {
                result++;
            }
            else
            {
                break;
            }
        }

    }
    
    cout << result << endl;
}