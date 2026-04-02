#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int alphabet[200] = {0};
    char arr[101] = {0};
    cin >> arr;
    int i;
    char j;

    for(i = 0; i < 101; i++)
    {
        for(j = 'a'; j <= 'z'; j++)
        {
            if(arr[i] == j)
            {
                ++(alphabet[j]);
            }
        }
    }


    for(j = 'a'; j <= 'z'; j++)
        cout << alphabet[j] << ' ';

    cout <<'\n';

    return 0;
    

    
}