#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int year;
    int result = 0;
    cin>>year;

    if((year % 4 == 0) && (year % 100 != 0))
        result = 1;
    if((year % 400) == 0)
        result = 1;
    
    cout << result << '\n';
    
    return 0;
}