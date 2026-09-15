#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> container(3);

    for (size_t i = 0; i < 3; i++)
    {
        int a, b, c, d;

        cin >> a >> b >> c >> d;
        container[i].push_back(a);
        container[i].push_back(b);
        container[i].push_back(c);
        container[i].push_back(d);
    }

    for (size_t i = 0; i < 3; i++)
    {
        int temp = count(container[i].begin(), container[i].end(), 0);

        switch (temp)
        {
        case 0:
            cout << "E\n";
            break;
        case 1:
            cout << "A\n";
            break;
        case 2:
            cout << "B\n";
            break;
        case 3:
            cout << "C\n";
            break;
        case 4:
            cout << "D\n";
            break;
        }
    }
}
