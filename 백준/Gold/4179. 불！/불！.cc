#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int n, m;
string board[1002];
int fire_dist[1002][1002]; // 불의 도달 시간
int jh_dist[1002][1002];   // 지훈의 도달 시간
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    queue<pair<int, int>> fire_q;
    queue<pair<int, int>> jh_q;
    
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            fire_dist[i][j] = -1;
            jh_dist[i][j] = -1;
            if (board[i][j] == 'F') {
                fire_q.push({i, j});
                fire_dist[i][j] = 0;
            }
            if (board[i][j] == 'J') {
                jh_q.push({i, j});
                jh_dist[i][j] = 0;
            }
        }
    }
    
    // 불의 BFS
    while (!fire_q.empty()) {
        pair<int, int> cur = fire_q.front();
        fire_q.pop();
        
        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d]; // 수정된 부분
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (fire_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            fire_dist[nx][ny] = fire_dist[cur.x][cur.y] + 1;
            fire_q.push({nx, ny});
        }
    }
    
    // 지훈의 BFS
    while (!jh_q.empty()) {
        pair<int, int> cur = jh_q.front();
        jh_q.pop();
        
        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) { // 탈출 성공
                cout << jh_dist[cur.x][cur.y] + 1 << '\n';
                return 0;
            }
            // 지훈이 이동할 수 없는 칸 or 벽 무시
            if (jh_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            // 해당 칸에 불이 도달할 수 있는 경우 and 불이 이미 도달했거나 불이 더 빠른 경우 무시
            if (fire_dist[nx][ny] != -1 && fire_dist[nx][ny] <= jh_dist[cur.x][cur.y] + 1) continue;
            jh_dist[nx][ny] = jh_dist[cur.x][cur.y] + 1;
            jh_q.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE\n"; // 개행 추가
    return 0;
}