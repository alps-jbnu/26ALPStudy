#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue <int> Q;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        
        Q.push(temp);
        // 10 3 7 4 12 2
    }

    int ans = 0; 

    for(int i = 0; i < n; i++) {

        int AB = Q.front();

        Q.pop();
        
        queue <int> Qtemp = Q;

        for(int j = 0; j < n - i - 1; j++) {
            if(!Q.empty()) {
                int te = Qtemp.front();
                Qtemp.pop();

                if(te < AB) {
                    ans++;
                } else if (te >= AB) {
                    break;
                }
            } else {
                break;
            }
        }

    }

    printf("%d", ans);
}