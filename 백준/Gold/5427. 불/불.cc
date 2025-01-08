#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

string board[1002];
int fire_dist[1002][1002];
int sg_dist[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
    int w, h;
    cin >> w >> h;

    queue<pair<int, int>> fire_q;
    queue<pair<int, int>> sg_q;

    // 입력 및 초기화
    for (int i = 0; i < h; i++) {
        cin >> board[i];
        for (int j = 0; j < w; j++) {
            fire_dist[i][j] = -1;
            sg_dist[i][j] = -1;

            if (board[i][j] == '@') {
                sg_dist[i][j] = 0;
                sg_q.push({i, j});
            }
            if (board[i][j] == '*') {
                fire_dist[i][j] = 0;
                fire_q.push({i, j});
            }
        }
    }

    // 불의 BFS
    while (!fire_q.empty()) {
        auto cur = fire_q.front();
        fire_q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (fire_dist[nx][ny] != -1 || board[nx][ny] == '#') continue;

            fire_dist[nx][ny] = fire_dist[cur.x][cur.y] + 1;
            fire_q.push({nx, ny});
        }
    }

    // 상근의 BFS
    while (!sg_q.empty()) {
        auto cur = sg_q.front();
        sg_q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            // 탈출 성공 조건
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                cout << sg_dist[cur.x][cur.y] + 1 << '\n';
                return;
            }

            if (sg_dist[nx][ny] != -1 || board[nx][ny] == '#') continue;
            // 상근이가 이동하려는 곳에 불이 먼저 도달했으면 이동하지 못해야 함
            if (fire_dist[nx][ny] != -1 && fire_dist[nx][ny] <= sg_dist[cur.x][cur.y] + 1) continue;

            sg_dist[nx][ny] = sg_dist[cur.x][cur.y] + 1;
            sg_q.push({nx, ny});
        }
    }

    // 탈출 불가
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

// 기록
// 조건 fire_dist[nx][ny] <= sg_dist[cur.x][cur.y] + 1은 상근이가 불보다 늦게 도착하거나 동시에 도착하면 이동할 수 없도록 막는 조건.
// fire_dist[nx][ny] < sg_dist[cur.x][cur.y] + 1은 불이 상근이보다 먼저 도달했음을 의미하며, 이는 상근이가 이동할 수 없는 칸임을 나타냄.
// fire_dist[nx][ny] = sg_dist[cur.x][cur.y] + 1은 불과 상근이가 동시에 도달한 경우로, 상근이가 이동할 수 없는 칸.
