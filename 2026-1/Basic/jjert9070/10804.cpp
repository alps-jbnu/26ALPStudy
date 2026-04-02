#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void initAscendingVector(vector<int> &vec);
void userInput(vector<vector<int>> &vec2d);
void reverse(vector<int> &vec, const int begin, const int end);
void swapElements(vector<int> &vec, const int begin, const int end);
void Elements(vector<int> &vec);


int main(void)
{
    int begin, end;
    int i;
    vector<int> vec(20);
    vector<vector<int>> vec2d(10, vector<int>(2, 0));
    initAscendingVector(vec);
    userInput(vec2d);

    i = 0;
    for(i = 0; i < vec2d.size(); i++)
    {
        reverse(vec, vec2d[i][0], vec2d[i][1]);
    }
    Elements(vec);
    
}


void initAscendingVector(vector<int> &vec)
{
    int i;
    for(i = 0; i < vec.size(); i++)
    {
        vec[i] = (i + 1);
    }
}

void userInput(vector<vector<int>> &vec2d)
{
    int i;
    for(i = 0; i < vec2d.size(); i++)
    {
            cin >> vec2d[i][0] >> vec2d[i][1];
    }    
}

void reverse(vector<int> &vec,int begin, int end)
{
    int i, j;
    int temp;
    for(i = begin - 1, j = end - 1; i < j; i++, j--)
    {
        temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }
}

void Elements(vector<int> &vec)
{
    int i;
    for(i = 0; i < vec.size(); i++)
    {
        cout<< vec[i] << ' ';
    }
    cout << '\n';
}