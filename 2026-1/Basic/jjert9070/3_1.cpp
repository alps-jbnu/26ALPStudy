#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class _Stack
{
private:
    stack<int> S;

public:
    _Stack()
    {
    }
    void _push(int x)
    {
        S.push(x);
    }
    int _top()
    {
        return S.top();
    }
    int _pop()
    {
        int temp;
        temp = S.top();
        S.pop();
        return temp;
    }
    int _is_empty()
    {
        if(S.empty())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    _Stack _S;
    list<int> target;

    int n;
    int i = 0;
    int x;

    cin >> n;
    list<char> result;
    list<int> result_num;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        target.push_back(x);
    }

    i = 1; // 스텍이 비어있음
    int j = 0;
    for (list<int>::iterator iter = target.begin(); iter != target.end(); iter++)
    {
        while (1)
        {   
            if(_S._is_empty())
            {
                _S._push(i);
                result.push_back('+');
                i++;
            }
            else if (_S._top() > *iter)
            {
                result_num.push_back(_S._pop());
                result.push_back('-');
            }
            else if (_S._top() < *iter)
            {
                _S._push(i);
                result.push_back('+');
                i++;
            }
            else if (_S._top() == *iter)
            {
                result_num.push_back(_S._pop());
                result.push_back('-');
                break;
            }
            j++;
        }
    }
    cout << '\n';

    for(list<char>::iterator iter = result.begin(); iter != result.end(); iter++)
    {
        cout<<*iter<<'\n';
    }
    for(list<int>::iterator iter = result_num.begin(); iter != result_num.end(); iter++)
    {
        cout<<*iter<<'\n';
    }

    
    return 0;
}