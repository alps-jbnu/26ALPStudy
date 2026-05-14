#include <iostream>
#include <vector>
using namespace std;

typedef struct student {
    int gender;
    int grade;
} STUDENT;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    vector<STUDENT> stu;
    vector< vector< vector<STUDENT> > >table(7, vector< vector<STUDENT> >(2));
    int n;
    int k;
    int i, j;
    int counter=0;
    int result=0;
    
    cin >> n;
    cin >> k;
    stu.resize(n);

    for(i = 0; i < n; i++)
    {
        cin >> stu[i].gender;
        cin >> stu[i].grade;
    }

    for(i = 1; i <= 6; i++)
    {
        for(j = 0; j < n; j++)
        {
            if((stu[j].grade == i) && (stu[j].gender == 0))
            {
                table[i][0].push_back(stu[j]);
            }
            if((stu[j].grade == i) && (stu[j].gender == 1))
            {
                table[i][1].push_back(stu[j]);
            }
        }
    }

    for(i = 1; i <=6; i++)
    {
        for(j = 0; j < 2; j++)
        {
            for(auto it = table[i][j].begin(); it < table[i][j].end(); it++)
            {
                counter++;
            }
            if((counter / k == 0) && (counter % k == 0))
            {
                continue;
            }
            else if((counter / k == 0) && (counter % k != 0))
            {
                result++;
            }
            else if((counter / k != 0) && (counter % k == 0))
            {
                result+=counter/k;
            }
            else if((counter / k != 0) && (counter % k != 0))
            {
                result+=counter/k+1;
            }
            counter = 0;
        }
    }

    cout<<result<<'\n';


    return 0;
}