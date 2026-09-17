#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<int> container;

    for (size_t i = 0; i < 7; i++)
    {
        int temp;

        cin >> temp;

        if (temp % 2 == 0)
            continue;

        container.push_back(temp);
    }

    if (container.empty())
    {
        cout << -1;
        return 0;
    }

    cout << accumulate(container.begin(), container.end(), 0) << "\n";

    cout << *min_element(container.begin(), container.end());
}
