#include <bits/stdc++.h>
using namespace std;

int m, n, h; // m: 가로, n: 세로, h: 높이
int tomato[102][102][102];
int dist[102][102][102];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n >> h;
    
    queue<tuple<int, int, int>> q;
    
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> tomato[k][i][j];
                if (tomato[k][i][j] == 1) {
                    q.push({k, i, j}); // 익은 토마토 추가
                } else if (tomato[k][i][j] == 0) {
                    dist[k][i][j] = -1; // 익지 않은 토마토는 -1
                }
            }
        }
    }
    
    // BFS 탐색
    while (!q.empty()) {
        auto [z, x, y] = q.front();
        q.pop();
        
        for (int d = 0; d < 6; d++) { // 6방향 탐색
            int nz = z + dz[d];
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if (nz < 0 || nz >= h || nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 체크
            if (dist[nz][nx][ny] != -1) continue; // 이미 익었거나 방문한 경우 무시
            
            dist[nz][nx][ny] = dist[z][x][y] + 1;
            q.push({nz, nx, ny});
        }
    }
    
    // 결과 계산
    int maxDay = 0;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dist[k][i][j] == -1) { // 익지 않은 토마토가 있다면
                    cout << -1 << '\n';
                    return 0;
                }
                maxDay = max(maxDay, dist[k][i][j]);
            }
        }
    }
    cout << maxDay << '\n';
    return 0;
}
