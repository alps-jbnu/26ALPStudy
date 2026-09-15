#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int a, b, c;

    vector<int> containter;

    cin >> a >> b >> c;

    containter.push_back(a);
    containter.push_back(b);
    containter.push_back(c);

    sort(containter.begin(), containter.end());

    if (a == b && a == c && b == c)
    {
        cout << 10000 + a * 1000;
    }
    else if (containter[0] == containter[1])
    {
        cout << 1000 + containter[1] * 100;
    }
    else if (containter[2] == containter[1])
    {
        cout << 1000 + containter[1] * 100;
    }
    else
    {
        cout << containter[2] * 100;
    }
}
