#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);
    int n;
    int result;
    int final_max_value = INT_MIN;
    int current_sum = 0;
    int current_max = INT_MIN;

    std::vector<int> arr;
    std::cin>>n;

    arr.resize(n + 1);

    bool flag = false;

    for(size_t i = 1; i <= n; i++)
    {
        std::cin>>arr[i];
        if(arr[i] >= 0)
        {
            flag = true;
        }
    }

    
    for(size_t i = 1; i <= n; i++)
    {
        current_sum = current_sum + arr[i];
        current_sum = std::max(current_sum, arr[i]);

        if(final_max_value < current_sum)
        {
            final_max_value = current_sum;
        }
    }

    std::cout<<final_max_value<<'\n';

    return 0;

}