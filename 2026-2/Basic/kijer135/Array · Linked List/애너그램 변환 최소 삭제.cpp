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

    string sent1, sent2;

    cin >> sent1 >> sent2;

    sort(sent1.begin(), sent1.end());
    sort(sent2.begin(), sent2.end());

    string result1 = sent1, result2 = sent2;

    char temp = ' ';

    for (auto x : sent1)
    {
        // cout << x << " ";

        if (temp == x)
        {
            continue;
        }

        temp = x;

        auto s1count = count(sent1.begin(), sent1.end(), x);
        auto s2count = count(sent2.begin(), sent2.end(), x);

        int amount = 0;

        if (s2count > s1count)
        {
            amount = s1count;
        }
        else if (s2count < s1count)
        {
            amount = s2count;
        }
        else
        {
            amount = s1count;
        }

        // cout << amount << "\n";

        auto it1 = find(result1.begin(), result1.end(), x);

        for (size_t i = 0; i < amount; i++)
        {
            result1.erase(it1);
        }

        auto it2 = find(result2.begin(), result2.end(), x);

        for (size_t i = 0; i < amount; i++)
        {
            result2.erase(it2);
        }
    }

    cout << result1.length() + result2.length();
}
