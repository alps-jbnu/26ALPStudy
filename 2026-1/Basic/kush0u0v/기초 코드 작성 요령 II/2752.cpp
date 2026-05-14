#include <iostream>
#include <stdlib.h>
using namespace std;

int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    qsort(a, 3, sizeof(*a), compare);

    cout << a[0] << " " << a[1] << " " << a[2] << endl;
    return 0;
}