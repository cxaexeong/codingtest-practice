#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int tomato[1002][1002]; // 상자 상태
int dist[1002][1002];   // 익는 데 걸리는 날짜 저장
int m,n;
int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    queue<pair<int,int>> q;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
                q.push({i,j});        // 익은 토마토의 위치를 큐에 저장
            if (tomato[i][j] == 0)
                dist[i][j] = -1;      // 익지 않은 토마토는 -1로 초기화
        }
    
    // bfs 탐색
    while (!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            // 범위 밖 or 이미 익은 토마토 or 빈 칸(-1)이면 무시
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] != -1) continue;
            
            // 새롭게 익는 토마토 처리
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            q.push({nx,ny});
        }
    }
    
    // 결과 계산
    int maxDay = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == -1) {    // 익지 않은 토마토가 남았다면
                cout << -1;
                return 0;
            }
            maxDay = max(maxDay, dist[i][j]);
        }
    cout << maxDay;
    return 0;    
}