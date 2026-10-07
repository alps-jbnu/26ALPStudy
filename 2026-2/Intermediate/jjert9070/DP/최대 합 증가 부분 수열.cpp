#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    
    int n;
    int max_sum = 0;
    vector<int> arr;
    vector<int> dp;

    cin>>n;

    arr.resize(n, 0);
    dp.resize(n, 0);

    for(size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    dp[0] = arr[0];

    for(size_t i = 1; i < arr.size(); i++)
    {
        max_sum = 0;
        for(size_t j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
            {
                max_sum = max(max_sum, dp[j]);
            }
        }


        dp[i] = max_sum + arr[i];
    }

    std::cout<<*(max_element(dp.begin(), dp.end()));
    std::cout<<'\n';

    return 0;

}