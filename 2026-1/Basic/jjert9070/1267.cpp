#include <iostream>
#include <vector>
using namespace std;

int youngsik(vector<int> &callTime);
int minsik(vector<int> &callTime);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int counter;
    int i;
    int y_result, m_result;
   
    cin >> counter;
    vector<int> callTime(counter);
    
    for(i = 0; i < counter; i++)
    {
        cin >> callTime[i];
    }
    y_result = youngsik(callTime);
    m_result = minsik(callTime);
    
    if(y_result < m_result)
    {
        cout << "Y " << y_result << '\n';
    }
    else if(y_result == m_result)
    {
        cout << "Y M "<< m_result << '\n';
    }
    else if(y_result > m_result)
    {
        cout << "M " << m_result <<'\n';
    }

}

int youngsik(vector<int> &callTime)
{
    int i, j;
    int counter, temp;
    int result = 0;
    for(i = 0; i < callTime.size(); i++)
    {
        counter = 0;
        temp = callTime[i];
        result = result + (callTime[i] / 30 + 1)*10;
    }
    return result;
}

int minsik(vector<int> &callTime)
{
    int i, j;
    int counter, temp;
    int result = 0;
    for(i = 0; i < callTime.size(); i++)
    {
        counter = 0;
        result = result + (callTime[i] / 60 + 1)*15;

    }
    return result;
}
