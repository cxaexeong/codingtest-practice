#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[300][300];      // 빙산 높이를 저장하는 배열
int temp[300][300];       // 녹은 후의 상태를 저장
bool visited[300][300];   // 방문 여부 확인
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 빙산 녹이기 함수
void melt() {
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] > 0) {
                int water = 0; // 주변 바다의 개수를 셈
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 0)
                        water++;
                }
                temp[i][j] = max(0, board[i][j] - water); // 높이는 0 이하로 내려가지 않음
            }
        }
    }
    memcpy(board, temp, sizeof(board)); // 결과를 원래 배열로 복사
}

// BFS를 사용해 연결된 빙산을 탐색
void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && board[nx][ny] > 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

// 빙산의 덩어리 개수를 세는 함수
int countIcebergs() {
    memset(visited, false, sizeof(visited));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] > 0 && !visited[i][j]) {
                count++;
                bfs(i, j);
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    int years = 0;

    while (true) {
        int components = countIcebergs();
        if (components >= 2) { // 빙산이 분리된 경우
            cout << years << '\n';
            break;
        }
        if (components == 0) { // 빙산이 모두 녹아 없어진 경우
            cout << 0 << '\n';
            break;
        }
        melt(); // 빙산을 녹임
        years++;
    }

    return 0;
}
