#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    int m;
    std::vector<int> arr;
    std::vector<int> query;
    std::cin>>n;
    arr.resize(n);

    for(size_t i = 0; i < arr.size(); i++)
    {
        std::cin>>arr[i];
    }

    std::sort(arr.begin(), arr.end());

    std::cin>>m;
    query.resize(m);

    for(size_t i = 0; i < query.size(); i++)
    {
        std::cin>>query[i];
    }


    for(size_t i = 0; i < query.size(); i++)
    {
        int result = std::upper_bound(arr.data(), arr.data() + n, query[i]) - std::lower_bound(arr.data(), arr.data() + n, query[i]);
        std::cout<<result<<" "; 
    }

    std::cout<<'\n';



    return 0;
}