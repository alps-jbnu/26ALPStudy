#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> container(9);

    for (size_t i = 0; i < 9; i++)
    {
        cin >> container[i];
    }

    cout << *max_element(container.begin(), container.end()) << "\n";
    cout << max_element(container.begin(), container.end()) - container.begin() + 1;
}
