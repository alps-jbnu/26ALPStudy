#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int i, j;
    char _str_input[1001];
    char _str_target[1001];
    int alphabet_counter_1[200] = {0};
    int alphabet_counter_2[200] = {0};

    bool flag = false;
    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> _str_input;
        cin >> _str_target;

        if(strlen(_str_input) != strlen(_str_target))
        {
            flag = true;
        }
        if(flag == false)
        {
            for(j = 0; _str_target[j] != '\0' ; j++)
            {
                alphabet_counter_1[_str_target[j]] += 1; 
            }

            for(j = 0; _str_input[j] != '\0'; j++)
            {
                alphabet_counter_2[_str_input[j]] += 1;
            }

            for(j = 0; j < 200; j++)
            {
                if(alphabet_counter_1[j] != alphabet_counter_2[j])
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag == true)
        {
            cout<<"Impossible\n";
            flag = false;
        }
        else
        {
            cout<<"Possible\n";
        }
        fill(begin(_str_input), end(_str_input), 0);
        fill(begin(_str_target), end(_str_target), 0);
        fill(begin(alphabet_counter_1), end(alphabet_counter_1), 0);
        fill(begin(alphabet_counter_2), end(alphabet_counter_2), 0);
    }
        
    return 0;
    
}