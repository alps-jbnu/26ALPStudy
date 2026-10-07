#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    unsigned long long n;
    unsigned long long start = 2;
    unsigned long long end = 9;
    std::cin>>n;
    bool flag = true;
    if(n >= start && n <= end)
    {
        std::cout<<"Stan wins."<<'\n';
    }
    else
    {
        while(true)
        {
            if(flag == true)
            {
                start = end + 1;
                end = end * 2;
                flag = false;
            }
            else if(flag == false)
            {
                start = end + 1;
                end = end * 9;
                flag = true;
            }

            if(n >= start && n <= end)
            {
                if(flag == true)
                {
                    std::cout<<"Stan wins."<<'\n';
                    break;
                }
                else if(flag == false)
                {
                    std::cout<<"Ollie wins."<<'\n';
                    break;
                }
            }
            
        }
    }


}