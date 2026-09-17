#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int main()
{
    deque <char> dl;
    deque <char> dr;
    string S;
    int N;
    cin >> S >> N;
    for(int i = 0; i < S.length(); i++)
    {
        dl.push_back(S[i]);
    }
    while(N --)
    {
        char I;
        cin >> I;
        if(I == 'P')
        {
            char NI;
            cin >> NI;
            dl.push_back(NI);
        }
        else if(I == 'L')
        {
            if(dl.empty()) continue;
            dr.push_front(dl.back());
            dl.pop_back();
        }
        else if(I == 'D')
        {
            if(dr.empty()) continue;
            dl.push_back(dr.front());
            dr.pop_front();
        }
        else if(I == 'B')
        {
            if(dl.empty()) continue;
            dl.pop_back();
        }
    }
    while(!dl.empty())
    {
        cout << dl.front();
        dl.pop_front();
    }
    while(!dr.empty())
    {
        cout << dr.front();
        dr.pop_front();
    }
    return 0;
}
