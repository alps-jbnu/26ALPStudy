#include <iostream>
#include <vector>

std::vector<int> dpZero;
std::vector<int> dpOne;


void fibonacci(int n)
{
    dpOne[0] = 0;
    dpOne[1] = 1;
    dpOne[2] = 1;
    dpZero[0] = 1;
    dpZero[1] = 0;
    dpZero[2] = 1;


    if(n == 0)
    {
        return;
    }

    if(n == 1)
    {
        return;
    }

    if(n == 2)
    {
        return;
    }





    for(size_t i = 2; i <= n; i++)
    {
        dpOne[i] = dpOne[i - 1] + dpOne[i - 2];
        dpZero[i] = dpZero[i - 1] + dpZero[i - 2];
    }
    
}





int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);

    int T;
    std::cin>>T;

    dpZero.resize(100, 0);
    dpOne.resize(100, 0);

    for(size_t i = 0; i < T; i++)
    {
        int input_;
        int result;
        std::cin>>input_;
        fibonacci(input_);
        std::cout<<dpZero[input_]<<" "<<dpOne[input_]<<'\n';
        dpZero.assign(100, 0);
        dpOne.assign(100, 0);
    }


    return 0;
}