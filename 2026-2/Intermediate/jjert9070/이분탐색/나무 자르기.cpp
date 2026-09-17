#include <iostream>
#include <vector>
#include <algorithm>

int getMaxHeight(std::vector<int>& arr, int m)
{
    int sum = 0;
    int diff;
    int selectMin = *(std::min_element(arr.begin(), arr.end()));
    int selectMax = *(std::max_element(arr.begin(), arr.end()));

    int now = selectMin;

    while(true)
    {
        for(size_t i = 0; i < arr.size(); i++)
        {
            if(arr[i] >= now)
            {
                sum = sum + (arr[i] - now);
            }
        }

        if(sum == 0)
        {
            return -1;
        }


        if(sum == m)
        {
            return now;
        }
        else if(sum < m)
        {
            sum = 0;
            now = now + 1;
        }

    }



}



int main()
{
    int n;
    int m;
    int result;
    std::vector<int> arr;
    std::cin>>n>>m;

    arr.resize(n);



    for(size_t i = 0; i < n; i++)
    {
        std::cin>>arr[i];
    }


    result = getMaxHeight(arr, m);

    std::cout<<result<<'\n';
    

    return 0;
    
}