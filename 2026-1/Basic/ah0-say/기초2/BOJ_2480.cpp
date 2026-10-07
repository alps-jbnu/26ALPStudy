#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    int cash;
    cin >> a >> b >> c ;
    
    if (a==b && a==c)
    {
        cash = 10000 + a * 1000;
    }
    else if (a==b)
    {
        cash = 1000 + a * 100;
    }
    else if (a==c)
    {
        cash = 1000 + a * 100;
    }
    else if (b==c)
    {
        cash = 1000 + b * 100;
    }
    else
    {
        if (a>b && a>c)
        {
            cash = a * 100;
        }
        else if (b>a && b>c)
        {
            cash = b * 100;
        }
        else
        {
            cash = c * 100;
        }
    }
    
    cout << cash;
    return 0;
}
