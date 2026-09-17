#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void func(int a, int b)
{
    cout << b - a - 1 << "\n";

    for (size_t i = a + 1; i < b; i++)
    {
        cout << i << " ";
    }
    return;
}

int main()
{
    int a, b;

    cin >> a >> b;

    if (a == b)
    {
        cout << 0;
        return 0;
    }
    else if (a > b)
    {
        func(b, a);
    }
    else
    {
        func(a, b);
    }
}
