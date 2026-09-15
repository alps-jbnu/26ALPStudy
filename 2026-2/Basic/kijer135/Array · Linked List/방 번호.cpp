#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string sent;

    vector<char> container;

    int result = 1;

    cin >> sent;

    sort(sent.begin(), sent.end());

    for (auto x : sent)
    {

        if (x == '9')
        {
            x = '6';
        }

        if (x == '6')
        {
            auto temp = count(container.begin(), container.end(), '6');

            if (temp != 0 && temp % 2 == 0)
            {
                result++;
            }

            container.push_back(x);
        }
        else
        {

            if (count(container.begin(), container.end(), x) != 0)
            {
                result++;
            }

            container.push_back(x);
        }
    }

    cout << result;
}
