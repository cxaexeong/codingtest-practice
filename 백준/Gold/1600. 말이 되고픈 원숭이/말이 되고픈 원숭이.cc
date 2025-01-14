#include <bits/stdc++.h>
using namespace std;

const int MAX = 202;
int board[MAX][MAX];
int dist[MAX][MAX][32]; // k번 이동 상태에서 (x, y)의 최소 이동 거리
int dx[4] = {1, -1, 0, 0}; // 원숭이 이동
int dy[4] = {0, 0, 1, -1};
int hx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}; // 말 이동
int hy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k, w, h;
    cin >> k >> w >> h;
    
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) 
            cin >> board[i][j];
    
    memset(dist, -1, sizeof(dist));
    dist[0][0][0] = 0; // 시작점 거리 초기화
    
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    
    while (!q.empty()) {
        auto [cx, cy, ck] = q.front();
        q.pop();
        
        // 목표 지점 도달
        if (cx == h - 1 && cy == w - 1) {
            cout << dist[cx][cy][ck] << '\n';
            return 0;
        }
        
        // 원숭이 이동
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (board[nx][ny] == 1 || dist[nx][ny][ck] != -1) continue;
            
            dist[nx][ny][ck] = dist[cx][cy][ck] + 1;
            q.push({nx, ny, ck});
        }
        
        // 말 이동
        if (ck < k) {
            for (int d = 0; d < 8; d++) {
                int nx = cx + hx[d];
                int ny = cy + hy[d];
                
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (board[nx][ny] == 1 || dist[nx][ny][ck + 1] != -1) continue;
                
                dist[nx][ny][ck + 1] = dist[cx][cy][ck] + 1;
                q.push({nx, ny, ck + 1});
            }
        }
    }
    cout << -1 << '\n'; // 목표 지점 도달 불가능한 경우
    return 0;
}
