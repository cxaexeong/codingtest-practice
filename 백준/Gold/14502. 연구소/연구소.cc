#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int n, m;
int maxSafe = 0;
int board[10][10];
int tmp[10][10];
vector<pair<int, int>> empty_spaces;
vector<pair<int, int>> virus;
bool v[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
    queue<pair<int, int>> q;
    memset(v, false, sizeof(v));  // 방문 배열 초기화

    // 초기 바이러스 위치 큐에 삽입
    for (auto vv : virus) {
        q.push(vv);
        v[vv.first][vv.second] = true;
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (tmp[nx][ny] != 0 || v[nx][ny]) continue;

            tmp[nx][ny] = 2;
            v[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

// 안전 영역 개수 계산
int getSafeArea() {
    int safeCount = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (tmp[i][j] == 0) safeCount++;
    return safeCount;
}

// 벽 3개 선택 (조합 방식)
void buildwall(int count, int start) {
    if (count == 3) {  // 벽 3개를 다 세웠다면 바이러스 확산 후 안전영역 계산
        memcpy(tmp, board, sizeof(tmp));
        bfs();
        maxSafe = max(maxSafe, getSafeArea());
        return;
    }

    // 조합으로 3개 빈 칸 선택
    for (int i = start; i < empty_spaces.size(); i++) {
        auto [x, y] = empty_spaces[i];
        board[x][y] = 1;
        buildwall(count + 1, i + 1);
        board[x][y] = 0;  // 원상 복구
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) empty_spaces.push_back({i, j});
            if (board[i][j] == 2) virus.push_back({i, j});
        }
    }

    buildwall(0, 0);
    cout << maxSafe;
}
