#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int arr_A[100000];

int main() {
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr_A[i];
    int st = 0, en = n - 1;
    int best_st = st, best_en = en;
    while(st < en) {
        if(arr_A[st] + arr_A[en] == 0){
            best_st = st;
            best_en = en;
            break;
        }
        else if(arr_A[st] + arr_A[en] < 0){
            st++;
            if(st == en)
                break;
        }
        else {
            en--;
            if(st == en)
                break;
        }
        if(abs(arr_A[st] + arr_A[en]) < abs(arr_A[best_st] + arr_A[best_en])){
            best_st = st;
            best_en = en;
        }
    }
    cout << arr_A[best_st] << " " << arr_A[best_en] << "\n";
    return 0;