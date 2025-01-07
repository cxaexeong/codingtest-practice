#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int t, m, n, k;
int board[52][52]; // 배추밭 정보
bool v[52][52];    // 방문 여부 체크
int dx[4] = {1, 0, -1, 0}; // 상하좌우 방향 이동
int dy[4] = {0, 1, 0, -1};

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

            // 범위 체크 및 조건 확인
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (v[nx][ny] || board[nx][ny] == 0) continue;

            v[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> m >> n >> k;

        // 초기화
        memset(board, 0, sizeof(board));
        memset(v, false, sizeof(v));

        // 배추 위치 입력
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            board[x][y] = 1;
        }

        int cnt = 0;

        // 모든 위치 탐색
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1 && !v[i][j]) {
                    bfs(i, j); // 새로운 그룹 발견 시 BFS 호출
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
