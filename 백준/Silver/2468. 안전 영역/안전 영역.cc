#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int board[102][102];
bool v[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, max_h = 0, ans = 0;

void bfs(int x, int y, int h) {
    queue<pair<int,int>> q;
    q.push({x, y});
    v[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (v[nx][ny]) continue;

            if (board[nx][ny] > h) {
                v[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            max_h = max(max_h, board[i][j]); // 최대 높이 갱신
        }
    }

    for (int h = 0; h <= max_h; h++) {
        memset(v, false, sizeof(v)); // 방문 배열 초기화
        int safe_area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > h && !v[i][j]) {
                    bfs(i, j, h);
                    safe_area++;
                }
            }
        }
        ans = max(ans, safe_area); // 최대 안전 영역 갱신
    }

    cout << ans << '\n';
    return 0;
}