#include <iostream>
#include <vector>
using namespace std;

int youngsik(vector<int> &callTime);
int minsik(vector<int> &callTime);
int sumOfTime(vector<int> &callTime);

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int counter;
    int i;
    
    cin >> counter;
    vector<int> callTime(counter);

    for(i = 0; i < counter; i++)
    {
        cin >> callTime[i];
    }
    if(youngsik(callTime) < minsik(callTime))
    {
        cout << "M " << youngsik(callTime) << '\n';
    }
    else if(youngsik(callTime) == minsik(callTime))
    {
        cout << "Y M "<< minsik(callTime) << '\n';
    }
    else if(youngsik(callTime) > minsik(callTime))
    {
        cout << "M " << minsik(callTime) <<'\n';
    }

}

int youngsik(vector<int> &callTime)
{
    int result = 0;
    int i;
    bool flag = false;
    result = sumOfTime(callTime);
    if(result % 30 != 0) flag = true;
    if(flag == true) result = (result / 30) * 10 + 10;
    else result = (result / 30) * 10;
    return result;
}
int minsik(vector<int> &callTime)
{
    int result = 0;
    int i;
    bool flag = false;
    result = sumOfTime(callTime);
    if(result % 60 != 0) flag = true;
    if(flag == true) result = (result / 60) * 15 + 15;
    else result = (result / 60) * 15;
    return result;
}

int sumOfTime(vector<int> &callTime)
{
    int result = 0;
    int i;
    for(i = 0; i < callTime.size(); i++)
    {
        result = result + callTime[i];
    }

    return result;
}
