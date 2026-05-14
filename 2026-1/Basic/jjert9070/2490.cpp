#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int yut[3][4] = {0};
    int (*yut_arr_row)[4] = yut;
    int i, j;
    int counter=0;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j<4; j++)
        {
            cin >> *(*(yut_arr_row+i)+j);
        }
    }

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j<4 ;j++)
        {
            if( *(*(yut_arr_row+i)+j) == 1 )
                counter++;
        }
        if(counter == 0)
            cout << 'D' << '\n';
        else if(counter == 1)
            cout << 'C' << '\n';
        else if(counter == 2)
            cout << 'B' << '\n';
        else if(counter == 3)
            cout << 'A' << '\n';
        else if(counter == 4)
            cout << 'E' << '\n';
        counter = 0;
    }

    

    return 0;
}