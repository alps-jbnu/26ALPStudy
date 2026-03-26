#include <iostream>
#include <climits>
using namespace std;

int retMax(const int* dice, const int size);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int d[3] = {0};
    int result;
    cin >> d[0] >> d[1] >> d[2];
    if((d[0] == d[1]) && (d[0] == d[2]) && (d[1] == d[2]))
    {
         result = 10000 + d[0]*1000;
    }
    else if((d[0] == d[1]) || (d[0] == d[2]) || (d[1] == d[2]))
    {
         if(d[0] == d[1])
        {
            result = 1000 + d[0]* 100;

        }
         else if(d[0] == d[2])
         {
            result = 1000 + d[0] * 100;

         }
        else if(d[1] == d[2])
        {
            result = 1000 + d[1] * 100;
        }
    }
    else if(d[0] != d[1] && d[0] != d[2] && d[1] != d[2])
    {
        result = retMax(d, 3) * 100;
    }
    
    cout << result << '\n';
    return 0;

}

int retMax(const int* dice, const int size)
{
    int i;
    int max = INT_MIN;
    for(i = 0; i < size; i++)
        if(*(dice + i) > max)
            max = *(dice + i);

    return max;
}