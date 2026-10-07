#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int main()
{
    string S;
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        deque <char> dl;
        deque <char> dr;
        
        cin >> S;
        int k = S.length();
        
        for(int j = 0; j < k; j++)
        {
            char I = S[j];
            if(I == '<')
            {
                if(dl.empty()) continue;
                dr.push_front(dl.back());
                dl.pop_back();
            }
            else if(I == '>')
            {
                if(dr.empty()) continue;
                dl.push_back(dr.front());
                dr.pop_front();
            }
            else if(I == '-')
            {
                if(dl.empty()) continue;
                dl.pop_back();
            }
            else
            {
                dl.push_back(I);
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
        cout << "\n";
    }
    return 0;
}
