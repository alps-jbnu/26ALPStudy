#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int amount;

    cin >> amount;

    vector<int> cont(amount);

    for (size_t i = 0; i < amount; i++)
    {
        cin >> cont[i];
    }

    int num;

    cin >> num;

    cout << count(cont.begin(), cont.end(), num);
}
