#include <iostream>
#include <vector>

using namespace std;

bool selected[5][6]; // 7개로 선택된 칸을 표시할 배열

// idx: 0부터 24까지 탐색할 현재 번호
// cnt: 현재까지 고른 개수
void combination(int idx, int cnt) {
    // 1. 탈출 조건: 7개를 다 골랐을 때!
    if (cnt == 7) {
        // 여기서 고른 7개를 가지고 원하는 작업(연결성 확인, Y 개수 확인 등)을 수행하면 됩니다.
        return;
    }

    // 2. 조합 선택 루프
    // i를 idx부터 시작하는 것이 핵심입니다. (그래야 조합이 중복 없이 순서대로 뽑힙니다.)
    for (int i = idx; i < 25; i++) {
        int r = i / 5; // 행
        int c = i % 5; // 열

        selected[r][c] = true;          // i번째 칸을 선택함
        combination(i + 1, cnt + 1);    // 다음 칸(i+1)로 넘어가고 개수 +1
        selected[r][c] = false;         // 백트래킹 (원상복구)
    }
}

int main() {
    // 0번부터 시작해서 0개를 고른 상태로 조합 시작
    cin
    combination(0, 0);
    return 0;
}