#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int amount;

    cin >> amount;

    while (amount--)
    {
        string sent;

        cin >> sent;

        list<char> result;

        auto it = result.begin();

        for (char x : sent)
        {
            if (x == '<')
            {
                if (it != result.begin())
                    --it;
            }
            else if (x == '>')
            {
                if (it != result.end())
                    ++it;
            }
            else if (x == '-')
            {
                if (it != result.begin())
                {
                    auto eraseIt = it;
                    --eraseIt;
                    result.erase(eraseIt);
                }
            }
            else
            {
                result.insert(it, x);
            }
        }

        for (auto x : result)
        {
            cout << x;
        }
        cout << '\n';
    }
}
