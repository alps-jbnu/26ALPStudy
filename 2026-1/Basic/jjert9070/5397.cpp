#include <iostream>
#include <list>

using namespace std;
void move_left(list<char>& _str, list<char>::iterator& cursor);
void move_right(list<char>& _str, list<char>::iterator& cursor);
void backspace(list<char>& _str, list<char>::iterator& cursor);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    list<char> _str;
    int n;
    int i, j;
    list<char>::iterator _str_cursor;
    string data;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> data;
        _str_cursor = _str.begin();
        for(j = 0; j < data.length(); j++)
        {
            if((data[j]) == '<')
            {
                move_left(_str, _str_cursor);
            }
            else if(data[j] == '>')
            {
                move_right(_str, _str_cursor);
            }
            else if(data[j] == '-')
            {
                backspace(_str, _str_cursor);
            }
            else
            {
                _str.insert(_str_cursor, data[j]);
            }
        }
    
        for(list<char>::iterator it = _str.begin(); it != _str.end(); it++)
        {
            cout << *it;
        }
        cout<<'\n';
        _str.clear();
    }

    return 0;
}

void move_left(list<char>& _str, list<char>::iterator& cursor)
{
    if(cursor == _str.begin())
    {
        return;
    }
    else
    {
        cursor--;
    }
}

void move_right(list<char>& _str, list<char>::iterator& cursor)
{
    if(cursor == _str.end())
    {
        return;
    }
    else
    {
        cursor++;
    }
}

void backspace(list<char>& _str, list<char>::iterator& cursor)
{
    if(cursor == _str.begin())
    {
        return;
    }
    else
    {
        cursor--;
        cursor = _str.erase(cursor);
    }

}