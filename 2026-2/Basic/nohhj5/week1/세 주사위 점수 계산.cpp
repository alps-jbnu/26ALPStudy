#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if ((A == B) && (B == C)) {
        cout << 10000 + A*1000;
    }
    else if ((A == B) && (B != C)) {
        cout << 1000 + A*100;
    }
    else if ((B == C) && (C != A)) {
        cout << 1000 + B*100;
    }
    else if ((C == A) && (A != B)) {
        cout << 1000 + C*100;
    }
    else {
        vector<int> v = {A, B, C};
        int max_val = *max_element(v.begin(), v.end()); 
        cout << max_val*100;
    }
        
    return 0;
}
