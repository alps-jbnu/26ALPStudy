#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int MX = 1000005;
int data[MX];
int pos = 0;

void push(int x)
{
    data[pos] = x;
    pos++;
}

void pop()
{
    if(pos < 0)
    {
        return;
    }
    else
    {
        cout<<data[pos]<<'\n';
        pos--;   
    }
}

int top()
{
    return data[sizeof(data) / sizeof(int) - 1];
}

void test()
{
    push(7);
    push(9);
    pop();
    pop();
    pop();
    top();
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    test();
    
}