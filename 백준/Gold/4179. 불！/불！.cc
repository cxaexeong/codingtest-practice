#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int r, c;
string board[1002];
int fire_dist[1002][1002];
int jh_dist[1002][1002];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    queue<pair<int, int>> fire_q;
    queue<pair<int, int>> jh_q;

    for (int i = 0; i < r; i++) {
        cin >> board[i];
        for (int j = 0; j < c; j++) {
            fire_dist[i][j] = -1;
            jh_dist[i][j] = -1;
            if (board[i][j] == 'F') {
                fire_dist[i][j] = 0;
                fire_q.push({i, j});
            }
            if (board[i][j] == 'J') {
                jh_dist[i][j] = 0;
                jh_q.push({i, j});
            }
        }
    }

    // 불의 BFS
    while (!fire_q.empty()) {
        pair<int, int> cur = fire_q.front();
        fire_q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (fire_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            fire_dist[nx][ny] = fire_dist[cur.x][cur.y] + 1;
            fire_q.push({nx, ny});
        }
    }

    // 지훈이의 BFS
    while (!jh_q.empty()) {
        pair<int, int> cur = jh_q.front();
        jh_q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << jh_dist[cur.x][cur.y] + 1 << '\n';
                return 0;
            }
            if (jh_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if (fire_dist[nx][ny] != -1 && fire_dist[nx][ny] <= jh_dist[cur.x][cur.y] + 1) continue;

            jh_dist[nx][ny] = jh_dist[cur.x][cur.y] + 1;
            jh_q.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
