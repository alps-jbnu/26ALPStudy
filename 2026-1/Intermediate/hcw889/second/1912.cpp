#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        v.push_back(t);
    }
    vector<int> dp(n + 1);
    dp[0] = v[0];
    int ans = dp[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(v[i], dp[i - 1] + v[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}