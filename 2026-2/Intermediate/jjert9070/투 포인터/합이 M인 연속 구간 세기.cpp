#include <iostream>
#include <vector>
#include <algorithm>

int consecutiveCount(std::vector<int>& arr, int m)
{
    int i;
    int j;
    long long result = 0;
    long long count = 0;
    i = 0;
    j = 0;

    result = result + arr[j];

    while(j < arr.size())
    {
        if(result < m)
        {
            j = j + 1;
            result = result + arr[j];   
        }
        else if(result > m)
        {
            result = result - arr[i];
            i = i + 1;
        }
        else if(result == m)
        {
            count = count + 1;
            i = i + 1;
            j = i;
            result = 0;
            result = result + arr[j];
        }

    }

    return count;
}



int main()
{
    int n;
    int m;
    int result;
    std::vector<int> arr;

    std::cin>>n>>m;
    arr.resize(n, 0);

    for(size_t i = 0; i < arr.size(); i++)
    {
        std::cin>>arr[i];
    }

    result = consecutiveCount(arr, m);

    std::cout<<result<<'\n';


    return 0;

}