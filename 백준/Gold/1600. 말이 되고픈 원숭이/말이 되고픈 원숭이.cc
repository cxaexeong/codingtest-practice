#include <bits/stdc++.h>
using namespace std;

struct state {
    int x, y, k, dist;
};

int main() {
    int k, w, h;
    cin >> k >> w >> h;

    vector<vector<int>> board(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
        }
    vector<vector<vector<bool>>> v(h, vector<vector<bool>>(w, vector<bool>(k + 1, false)));

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    int hourse_dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int hourse_dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

    queue<state> q;
    q.push({0, 0, 0, 0});
    v[0][0][0] = true;

    while (!q.empty()) {
        state cur = q.front();
        q.pop();

        if (cur.x == h - 1 && cur.y == w - 1) {
            cout << cur.dist << "\n";
            return 0;
        }

        // 일반 이동
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < h && ny < w && !v[nx][ny][cur.k] && board[nx][ny] == 0) {
                v[nx][ny][cur.k] = true;
                q.push({nx, ny, cur.k, cur.dist + 1});
            }
        }

        // 말 이동
        if (cur.k < k) {
            for (int i = 0; i < 8; ++i) {
                int nx = cur.x + hourse_dx[i];
                int ny = cur.y + hourse_dy[i];

                if (nx >= 0 && ny >= 0 && nx < h && ny < w && !v[nx][ny][cur.k + 1] && board[nx][ny] == 0) {
                    v[nx][ny][cur.k + 1] = true;
                    q.push({nx, ny, cur.k + 1, cur.dist + 1});
                }
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}