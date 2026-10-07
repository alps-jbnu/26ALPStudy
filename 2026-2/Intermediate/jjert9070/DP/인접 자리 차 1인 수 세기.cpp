#include <iostream>
#include <vector>
#include <numeric>

#define MOD 1000000000


int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);
    int n;
    unsigned long long result;
    std::vector<std::vector<unsigned long long>> dp;
    std::vector<std::vector<unsigned long long>> dpMod;
    std::cin>>n;

    dp.resize(n + 1, std::vector<unsigned long long>(10, 0));
    dpMod.resize(n + 1, std::vector<unsigned long long>(10, 0));

    std::fill(dp[1].begin() + 1, dp[1].end(), 1);
    std::fill(dpMod[1].begin() + 1, dpMod[1].end(), 1);

    for(size_t i = 2; i <= n; i++)
    {
        for(size_t j = 0; j <= 9; j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i - 1][1];
                dpMod[i][j] = dpMod[i - 1][1] % MOD;
                continue;
            }
            else if(j == 9)
            {
                dp[i][j] = dp[i - 1][8];
                dpMod[i][j] = dpMod[i - 1][8] % MOD;
                continue;
            }

            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

            // 모듈러 연산의 성질
            dpMod[i][j] = dpMod[i - 1][j - 1] % MOD + dpMod[i - 1][j + 1] % MOD;
        }
    }
    
    result = std::accumulate(dpMod[n].begin(), dpMod[n].end(), 0ULL);

    std::cout<<result % MOD <<'\n';



    return 0;
}