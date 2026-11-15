#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
int dist[1000001];
bool visited[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>> F >> S >> G >> U >> D;

    queue<int> q;
    q.push(S);
    visited[S] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == G) {
            cout << dist[cur] << '\n';
            return 0;
        }

       // 위
        int up = cur + U;
        if (up >= 1 && up <= F && !visited[up]) {
            visited[up] = true;
            dist[up] = dist[cur] + 1;
            q.push(up);
        }

        // 아래
        int down = cur - D;
        if (down >= 1 && down <= F && !visited[down]) {
            visited[down] = true;
            dist[down] = dist[cur] + 1;
            q.push(down);
        }
    }

    cout << "use the stairs\n";
    return 0;
}
