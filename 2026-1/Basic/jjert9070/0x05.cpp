#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x)
{
    dat[pos++] = x;
}

void pop()
{
    if(pos-1 < 0)
    {
        return;
    }
    else
    {
        cout<<dat[pos-1]<<'\n';
        pos--;   
    }
}

int top()
{
    return dat[pos-1];
}

void test()
{
    push(7);
    push(9);
    pop();
    pop();
    pop();
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    test();
    
}