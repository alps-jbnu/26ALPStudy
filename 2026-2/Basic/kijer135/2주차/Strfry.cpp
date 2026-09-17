#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt;

    cin >> cnt;

    for (size_t i = 0; i < cnt; i++)
    {
        string s1, s2;

        cin >> s1 >> s2;

        bool pos = true;

        for (auto x : s1)
        {
            int s1amt = count(s1.begin(), s1.end(), x), s2amt = count(s2.begin(), s2.end(), x);

            if (find(s2.begin(), s2.end(), x) == s2.end() || s1amt != s2amt)
            {
                pos = false;
                break;
            }
        }

        for (auto x : s2)
        {
            int s1amt = count(s1.begin(), s1.end(), x), s2amt = count(s2.begin(), s2.end(), x);

            if (find(s1.begin(), s1.end(), x) == s1.end() || s1amt != s2amt)
            {
                pos = false;
                break;
            }
        }

        if (pos)
        {
            cout << "Possible\n";
        }
        else
        {
            cout << "Impossible\n";
        }
    }
}
