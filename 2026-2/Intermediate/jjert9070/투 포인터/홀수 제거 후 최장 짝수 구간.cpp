#include <iostream>
#include <vector>
#include <algorithm>


long long slidingWindow(std::vector<long long>& arr, long long k)
{
    long long left = 0;
    long long right = 0;
    long long odd_count = 0;

    long long current_distance = 0;
    long long current_consecutive_even_count = 0;
    long long max_consecutive_even_count = 0;

    while(right < arr.size())
    {
        if(arr[right] % 2 == 1)
        {
            odd_count = odd_count + 1;
        }

        while(odd_count > k)
        {
            if(odd_count > k)
            {
                if(arr[left] % 2 == 1)
                {
                    odd_count = odd_count - 1;
                }
                left + 1;
            }
            left = left + 1;
        }

        current_distance = right - left + 1;
        current_consecutive_even_count = current_distance - odd_count;

        if(max_consecutive_even_count < current_consecutive_even_count)
        {
            max_consecutive_even_count = current_consecutive_even_count;
        }

        right = right + 1;
    }

    if(left == right)
    {
        return 0;
    }



    return max_consecutive_even_count;
}



int main()
{

    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);
    long long n;
    long long k;
    std::vector<long long> arr;

    std::cin>>n>>k;

    arr.resize(n, 0);

    for(size_t i = 0; i < arr.size(); i++)
    {
        std::cin>>arr[i];
    }




    long long result = slidingWindow(arr, k);


    std::cout<<result<<'\n';



    return 0;

}