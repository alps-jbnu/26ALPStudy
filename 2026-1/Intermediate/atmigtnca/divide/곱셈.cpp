#include <iostream>
using namespace std;
using ll = long long;

void solve()
{
    ll a, b, c, tmp = 1;
    cin >> a >> b >> c;

    while (b)
    {
        if (b & 1)
        {
            tmp = (tmp * a) % c;
        }
        b >>= 1;
        a = (a * a) % c;
    }
    cout << tmp << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();

    return 0;
}