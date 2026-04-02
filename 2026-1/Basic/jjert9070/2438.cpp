#include <iostream>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int i, j;
    int line;
    cin >> line;

    for(i = 0; i < line; i++)
    {
        for(j = 0; j < i + 1; j++)
        {
            cout<<'*';
        }
        cout<<'\n';
    }

    return 0;
}