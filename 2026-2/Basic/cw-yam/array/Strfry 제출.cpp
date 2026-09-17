#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string S1, S2;
    cin >> S1;
    while(cin >> S1){
        int arr[26] = {0, };
        bool ok = true;
        for(int i = 0; i < S1.length(); i++)
        {
            arr[S1[i] - 'a']++;
        }
        cin >> S2;
        for(int i = 0; i < S2.length(); i++)
        {
            arr[S2[i] - 'a'] --;
        }
        for(int i =0; i < 26; i++)
        {
            if(arr[i] != 0) {ok = false; break;}
        }
        if(ok) cout << "Possible\n";
        else cout << "Impossible\n";
    }
    return 0;
}

------------------------------------------------------------------------------------

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string S1, S2;
    cin >> S1;
    while(cin >> S1){
        int arr[26] = {0, };
        bool ok = true;
        for(int i = 0; i < S1.length(); i++)
        {
            arr[S1[i] - 'a']++;
        }
        cin >> S2;
        for(int i = 0; i < S2.length(); i++)
        {
            arr[S2[i] - 'a'] --;
        }
        for(int i =0; i < 26; i++)
        {
            if(arr[i] < 0) ok = false;
        }
        if(ok) cout << "Possible\n";
        else cout << "Impossible\n";
    }
    return 0;
}

#이거 왜 틀림?
