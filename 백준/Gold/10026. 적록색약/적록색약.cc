#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[102][102];
bool rgx[102][102];
bool rgo[102][102];
int n;

void bfs(int x, int y, bool v[102][102], bool is_rg_blind) {
    queue<pair<int, int>> q;
    q.push({x, y});
    v[x][y] = true;
    char color = board[x][y];

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // 범위 체크
            if (v[nx][ny]) continue; // 이미 방문한 경우 건너뜀

            // 적록색약의 경우 R, G를 동일하게 처리
            if (is_rg_blind) {
                if ((color == 'R' || color == 'G') && (board[nx][ny] == 'R' || board[nx][ny] == 'G')) {
                    v[nx][ny] = true;
                    q.push({nx, ny});
                } else if (color == board[nx][ny]) { // 동일 색상일 경우 처리 (추가)
                    v[nx][ny] = true;
                    q.push({nx, ny});
                }
            } else {
                // 일반인은 동일한 색상만 이동
                if (color == board[nx][ny]) {
                    v[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    
    // 일반인인 경우
    int rgx_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 방문하지 않은 경우만 탐색
            if (!rgx[i][j]) {
                bfs(i, j, rgx, false);
                rgx_cnt++;
            }
        }
    }
    
    // 적록색약인 경우
    int rgo_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 방문하지 않은 경우만 탐색
            if (!rgo[i][j]) {
                bfs(i, j, rgo, true);
                rgo_cnt++;
            }
        }
    }
    
    cout << rgx_cnt << " " << rgo_cnt << '\n';
    return 0;
}