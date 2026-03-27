#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<int> a_ary, b_ary, rst_ary;
int a, b;

void input()
{
    cin >> a >> b;

    a_ary.resize(a);
    b_ary.resize(b);

    for (auto& t : a_ary)
    {
        cin >> t;
    }
    for (auto& t : b_ary)
    {
        cin >> t;
    }
}

void solve()
{
    rst_ary.reserve(a);

    sort(a_ary.begin(), a_ary.end());
    sort(b_ary.begin(), b_ary.end());

    for (int num : a_ary)
    {
        bool chk = binary_search(b_ary.begin(), b_ary.end(), num);
        if (!chk)
        {
            rst_ary.push_back(num);
        }
    }
}

void output()
{
    cout << rst_ary.size() << '\n';
    if (rst_ary.size() > 0)
    {
        for (size_t i = 0; i < rst_ary.size(); i++)
        {
            cout << rst_ary[i] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
    output();

    return 0;
}
