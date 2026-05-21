#include <iostream>
using namespace std;

#define MAX 101

typedef struct{
    int x;
    int y;
    int Color;
} NODE;

NODE map [MAX][MAX];

NODE queue[MAX * MAX];
int rear = -1, front = -1;
int n; //n 배열 크기

//queue function
void init(){ rear = front = -1; }

void enqueue(int a, int b, int c){ 
    NODE temp;
    temp.x = a;
    temp.y = b;
    temp.Color = c;
    queue[++rear] = temp; // 전위 0부터
}

NODE dequeue(){ return queue[++front]; } // 전위 0부터

bool itsEmpty(){ return rear == front; }

// 미리
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int RGB() {
    bool visit[MAX][MAX] = {0};
    int count = 0;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {

            if (!visit[i][j]) {
                count ++; // 구역 

                init(); // BFS 초기화
                enqueue(i, j, map[i][j].Color);
                visit[i][j] = 1; // 방문

                while(!itsEmpty()) { // BFS 시작
                    NODE current = dequeue();

                    for(int a = 0; a < 4; a++) { // 4 방향 (북동남서)
                        int nx = current.x + dx[a];
                        int ny = current.y + dy[a];

                        //범위 체크 && 방문 여부 && 
                        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n
                        && !visit[nx][ny] 
                        && map[nx][ny].Color == current.Color) {
                            visit[nx][ny] = 1;
                            enqueue(nx, ny, map[nx][ny].Color);
                        }
                    }
                }
            }

        }
    }
    return count;
}

int RB() {
    bool visited[MAX][MAX] = {};
    int count = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visited[i][j]) {
                count++;
                init();
                enqueue(i, j, map[i][j].Color);
                visited[i][j] = true;

                while (!itsEmpty()) {
                    NODE cur = dequeue();
                    for (int d = 0; d < 4; d++) {
                        int nx = cur.x + dx[d];
                        int ny = cur.y + dy[d];
                        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n // 범위
                        && !visited[nx][ny] // 방문여부
                        && (map[nx][ny].Color == cur.Color // 똑같거나
                        || (map[nx][ny].Color != 'B' && cur.Color != 'B'))) { // B가 아닐때
                            visited[nx][ny] = true;
                            enqueue(nx, ny, map[nx][ny].Color);
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char temp;
            cin >> temp;

            NODE temp2;
            temp2.x = i;
            temp2.y = j;
            temp2.Color = temp;

            map[i][j] = temp2;
        }
    }

    cout << RGB() << " " << RB() << endl;
    return 0;
}