#include <iostream>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int line;
    int i, j;

    cin>>line;

    for(i = 0; i < line; i++)
    {
        for(j = 0; j < i; j++)
        {
            cout<<' ';
        }
        for(j = 0; j < (2*line-1)-2*i; j++)
        {
            cout<<'*';
        }

        cout<<'\n';
    }
}