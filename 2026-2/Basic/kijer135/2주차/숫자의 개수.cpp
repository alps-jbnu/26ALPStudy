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

    int a, b, c;

    vector<char> container;

    cin >> a;
    cin >> b;
    cin >> c;

    int num = a * b * c;

    while (num > 0)
    {
        char temp = num % 10 + 48;

        container.push_back(temp);

        num /= 10;
    }

    for (size_t i = 0; i < 10; i++)
    {
        cout << count(container.begin(), container.end(), i + 48) << '\n';
    }
}
