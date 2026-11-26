#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

// (난이도, 문제 번호) 형태를 저장할 구조체/페어
// 난이도가 같다면 문제 번호가 큰 것이 뒤로 가도록 정렬됨
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    set<pii> s; // 정렬 관리용 (난이도, 문제 번호)
    map<int, int> prob_to_level; // 문제 번호로 난이도를 빠르게 찾기 위함 (P -> L)

    for (int i = 0; i < N; i++) {
        int p, l;
        cin >> p >> l;
        s.insert({ l, p });
        prob_to_level[p] = l;
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int p, l;
            cin >> p >> l;
            s.insert({ l, p });
            prob_to_level[p] = l;
        }
        else if (cmd == "solved") {
            int p;
            cin >> p;
            int l = prob_to_level[p];
            s.erase({ l, p });
            prob_to_level.erase(p);
        }
        else if (cmd == "recommend") {
            int x;
            cin >> x;
            if (x == 1) {
                // 가장 어려운 문제 (세트의 가장 마지막 원소)
                cout << s.rbegin()->second << "\n";
            }
            else {
                // 가장 쉬운 문제 (세트의 가장 첫 번째 원소)
                cout << s.begin()->second << "\n";
            }
        }
    }

    return 0;
}