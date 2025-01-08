#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int board[52][52];
bool v[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n, k;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    v[x][y] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            // 범위를 벗어나거나 이미 방문한 경우
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (v[nx][ny] || board[nx][ny] == 0) continue;

            q.push({nx, ny});
            v[nx][ny] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> m >> n >> k;

        // 초기화
        memset(board, 0, sizeof(board));
        memset(v, false, sizeof(v));

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            board[x][y] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1 && !v[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
