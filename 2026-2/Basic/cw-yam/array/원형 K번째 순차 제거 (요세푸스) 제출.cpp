#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    int K, N;
    cin >> K >> N;
    cout << "<";
    for(int i = 1; i <= K; i++)
    {
        q.push(i);
    }
    while(!q.empty())
    {
        for(int i = 0; i < N - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        if(!q.empty()) cout << ", ";
    }
    cout << ">";
    return 0;
}
