#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int board[102][102];
bool v[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> m >> n >> k;

    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                board[y][x] = 1; // x와 y의 순서를 수정
            }
        }
    }

    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1 || v[i][j]) continue;

            queue<pair<int, int>> q;
            q.push({i, j});
            v[i][j] = true;
            int area = 0;

            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                area++;

                for (int d = 0; d < 4; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] == 1 || v[nx][ny]) continue;

                    q.push({nx, ny});
                    v[nx][ny] = true;
                }
            }
            ans.push_back(area);
            cnt++;
        }
    }
    sort(ans.begin(), ans.end());
    cout << cnt << '\n';
    for (int a : ans)
        cout << a << ' ';
    return 0;
}
