#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<int> n_ary;
int m, n;

void input()
{
    cin >> m >> n;
    n_ary.resize(n);

    for (auto num : n_ary)
    {
        cin >> num;
    }
    sort(n_ary.begin(), n_ary.end());
}

void solve()
{
    int mAx = 10;
    // int max = *(n_ary.end() - 1);
    // cout << mAx << '\n';

    while (mAx > 0)
    {
        int tmp = 0;
        auto low_idx = lower_bound(n_ary.begin(), n_ary.end(), mAx);
        int idx = distance(n_ary.begin(), low_idx);
        cout << idx << '\n';
        cout << mAx << '\n';

        for (int i = idx; i < n; i++)
        {
            cout << "lol\n";
            tmp += n_ary[i] / mAx;
            cout << tmp << '\n';
        }
        if (tmp == m)
        {
            cout << mAx << '\n';
            return;
        }
        mAx--;
    }
    cout << "hello\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();

    return 0;
}
