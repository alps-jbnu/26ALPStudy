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

    int num, ass;

    cin >> num >> ass;

    list<int> cont;
    vector<int> result;

    for (size_t i = 1; i <= num; i++)
    {
        cont.push_back(i);
    }

    auto it = cont.begin();

    while (!cont.empty())
    {
        for (size_t i = 0; i < ass - 1; i++)
        {
            ++it;
            if (it == cont.end())
            {
                it = cont.begin();
            }
        }

        result.push_back(*it);

        it = cont.erase(it);

        if (it == cont.end())
        {
            it = cont.begin();
        }

        /*for (auto it2 = cont.begin(); it2 != cont.end(); it2++)
        {
            cout << *it2 << " ";
        }
        cout << "\n";*/
    }

    cout << "<";
    for (size_t i = 0; i < num - 1; i++)
    {
        cout << result[i] << ", ";
    }

    cout << result[num - 1] << ">";
}
