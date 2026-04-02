#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int TestCase;
    cin >> TestCase;
    while (TestCase--)
    {
        int n;
        cin >> n;
        vector<long long> dp(101);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        dp[5] = 2;
        for (int i = 6; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 5];
        }
        cout << dp[n] << "\n";
    }

    return 0;
}