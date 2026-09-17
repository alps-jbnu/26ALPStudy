#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int count;

    cin >> count;

    for (size_t i = 0; i < count; i++)
    {
        int a, b;

        cin >> a >> b;

        cout << a + b << "\n";
    }
}
