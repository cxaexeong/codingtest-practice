#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
string board[102];
int dist[102][102];
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i]; // 한 줄 전체 입력받음, string 타입이라 이중 for문 런타임에러 남
    }
    
    // 초기 설정
    queue<pair<int,int>> q;
    q.push({0,0});
    dist[0][0] = 1; // 시작 위치 거리
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            // 범위 밖 or 벽 or 이미 방문한 경우 건너뜀
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == '0' || dist[nx][ny] > 0) continue;
            dist[nx][ny] = dist[cur.x][cur.y] + 1; // 거리 갱신
            q.push({nx,ny});
        }
    }
    cout << dist[n-1][m-1];
    return 0;
}