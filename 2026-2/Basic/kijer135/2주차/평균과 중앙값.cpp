#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> cont(5);

    for (size_t i = 0; i < 5; i++)
    {
        cin >> cont[i];
    }

    cout << accumulate(cont.begin(), cont.end(), 0) / 5 << '\n';

    sort(cont.begin(), cont.end());

    cout << cont[2];
}
