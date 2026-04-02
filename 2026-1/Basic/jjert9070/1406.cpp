#include <iostream>
#include <list>
using namespace std;

void move_left(list<char>& text, list<char>::iterator& cursor);
void move_right(list<char>& text, list<char>::iterator& cursor);
void backspace(list<char>& text, list<char>::iterator& cursor);
void add_char(list<char>& text, list<char>::iterator& cursor);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    list<char> text;
    int n;
    char command;
    string data;
    int i;
    
    list<char>::iterator cursor = text.begin();
    cin >> data;
    for(i = 0; i < data.length(); i++)
    {
        text.push_back(data[i]);
    }


    cursor = text.end();
    cin>>n;
    
    for(i = 0; i < n; i++)
    {
        cin >> command;
        if(command == 'L')
        {
             move_left(text, cursor);
        }
        else if(command == 'D')
        {
             move_right(text, cursor);
        }
        else if(command == 'B')
        {
            backspace(text, cursor);
        }
        else if(command == 'P')
        {
            add_char
        (text, cursor);
        }
    }

    for(auto it = text.begin(); it != text.end(); it++)
    {
        cout<<*it;
    }
   
    cout<<'\n';

    return 0;
    
    

}


void move_left(list<char>& text, list<char>::iterator& cursor)
{
    if(cursor == text.begin())
    {
        return;
    }
    else
    {
        --cursor;
    }
}

void move_right(list<char>& text, list<char>::iterator& cursor)
{
    if(cursor == text.end())
    {
        return;
    }
    else
    {
        ++cursor;
    }
}

void backspace(list<char>& text, list<char>::iterator& cursor)
{
    if(cursor == text.begin())
    {
        return;
    }
    else
    {
        cursor--;
        cursor = text.erase(cursor);
    }

}

void add_char(list<char>& text, list<char>::iterator& cursor)
{
    char _input;
    cin >> _input;
    cursor = text.insert(cursor, _input);
    cursor++;
}