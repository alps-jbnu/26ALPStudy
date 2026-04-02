#include <iostream>
using namespace std;
void sum(int data_1, int data_2);

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int line;
    int data_1, data_2;
    int i;

    cin >> line;

    for(i = 0; i < line; i++)
    {   
        cin >> data_1 >> data_2;
        sum(data_1, data_2);
    }


}

void sum(int data_1, int data_2)
{
    cout << data_1 + data_2 << '\n';
}

