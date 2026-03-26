#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int n, x;
    std::cin >> n >> x;

    int *pArr = (int*)malloc(sizeof(int) * n);

    for(int i=0; i < n; i++)
        std::cin >> pArr[i];
    for(int i=0; i < n; i++){
        if(x > pArr[i])
            cout << pArr[i] << endl;
    }
}