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

    string sent;

    cin >> sent;

    list<char> cont;

    for (auto x : sent)
    {
        cont.push_back(x);
    }

    auto it = cont.end();

    int amount;

    cin >> amount;

    for (size_t i = 0; i < amount; i++)
    {
        char temp;

        cin >> temp;

        if (temp == 'L')
        {
            if (it != cont.begin())
                --it;
        }
        else if (temp == 'D')
        {
            if (it != cont.end())
                ++it;
        }
        else if (temp == 'B')
        {
            if (it != cont.begin())
            {
                auto tem = it;
                --tem;
                cont.erase(tem);
            }
        }
        else if (temp == 'P')
        {
            char word;

            cin >> word;

            cont.insert(it, word);
        }
    }

    for (auto x : cont)
    {
        cout << x;
    }
}
