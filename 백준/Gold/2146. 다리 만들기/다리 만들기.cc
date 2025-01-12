#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int board[102][102];
int grid[102][102];
bool v[102][102];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void mark(int x, int y, int id) {
    queue<pair<int, int>> q;
    q.push({x, y});
    v[x][y] = true;
    grid[x][y] = id;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == 1 && !v[nx][ny]) {
                v[nx][ny] = true;
                q.push({nx, ny});
                grid[nx][ny] = id;
            }
        }
    }
}

int bfs(int id) {
    queue<pair<int, int>> q;
    int dist[102][102];
    memset(dist, -1, sizeof(dist));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == id) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }

    int min_dist = 1e9;
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (grid[nx][ny] > 0 && grid[nx][ny] != id) {
                    min_dist = min(min_dist, dist[cx][cy]);
                } else if (grid[nx][ny] == 0 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[cx][cy] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return min_dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; // 추가
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int id = 0;
    memset(v, false, sizeof(v));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == 1 && !v[i][j])
                mark(i, j, ++id);

    int result = 1e9;
    for (int i = 1; i <= id; i++) // 수정
        result = min(result, bfs(i));

    cout << result << '\n';
    return 0;
}
