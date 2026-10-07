#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(0);

    int n;
    vector<int> arr;
    vector<int> dp;
    vector<int> container;

    cin>>n;
    arr.resize(n, 0);
    dp.resize(n, 0);

    for(size_t i = 0; i < n; i++)
    {
        cin>>arr[i];
    }



    dp[0] = 1;

    for(int i = 1; i < arr.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
            {
                container.push_back(dp[j]);
            }
        }

        if(container.empty())
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = *(max_element(container.begin(), container.end())) + 1;
        }
        
        container.clear();
    }

    
    std::cout<<*(max_element(dp.begin(), dp.end()))<<'\n';

    return 0;

}