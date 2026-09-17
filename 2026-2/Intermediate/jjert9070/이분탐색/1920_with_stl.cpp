#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(NULL);
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

    for(size_t j = 0; j < query.size(); j++)
    {
        if(std::binary_search(arr.begin(), arr.end(), query[j]) == true)
        {
            std::cout<<"1"<<'\n';
        }
        else
        {
            std::cout<<"0"<<'\n';
        }
    }


    return 0;
    
}