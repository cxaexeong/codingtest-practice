#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[1001];
int dist[1001][1001][2]; // 거리 배열: [x][y][벽 부쉈는지 여부]
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs() {
    queue<tuple<int, int, int>> q; // (x, y, 벽 부쉈는지 여부)
    q.push({0, 0, 0});             // 시작점
    dist[0][0][0] = 1;             // 시작 지점의 거리

    while (!q.empty()) {
        auto [x, y, broken] = q.front();
        q.pop();

        // 목적지 도달
        if (x == n - 1 && y == m - 1)
            return dist[x][y][broken];

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            // 범위 초과
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            // 벽이면서 아직 부수지 않은 경우
            if (board[nx][ny] == '1' && broken == 0 && dist[nx][ny][1] == 0) {
                dist[nx][ny][1] = dist[x][y][0] + 1;
                q.push({nx, ny, 1}); // 벽 부순 상태로 이동
            }

            // 빈 칸이고 방문하지 않은 경우
            if (board[nx][ny] == '0' && dist[nx][ny][broken] == 0) {
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.push({nx, ny, broken}); // 현재 상태 유지
            }
        }
    }
    return -1; // 목적지에 도달할 수 없는 경우
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    memset(dist, 0, sizeof(dist)); // 거리 배열 초기화

    cout << bfs() << '\n';
    return 0;
}
