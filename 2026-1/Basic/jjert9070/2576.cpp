#include <iostream>
#include <climits>

using namespace std;


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int data[7] = {0};
    int i;
    int result = 0;
    int min = INT_MAX;
    bool flag = false;
    

    for(i = 0; i < 7; i++)
    {
        cin >> data[i];
    }

    for(i = 0; i < 7; i++)
    {
        if((data[i] % 2) == 1)
        {
            flag = true;
            if(data[i] < min)
            {
                min = data[i];
            }
            result = result + data[i];
        }
        
    }

    if(flag == false)
    {
        cout << "-1" << '\n';
    }
    else
    {
        cout << result << '\n';
        cout << min << '\n';
    }


    return 0;

}