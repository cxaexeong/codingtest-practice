#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int board[302][302];
bool v[302][302];

int bfs(int l, int si, int sj, int ei, int ej) {
    queue<pair<int,int>> q;
    q.push({si,sj});
    v[si][sj] = true;
    
    int dist[302][302] = {0}; // 이동 횟수 저장
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        
        // 목적지에 도달하면 이동 횟수 반환
        if (cur.x == ei && cur.y == ej)
            return dist[cur.x][cur.y];
        
        for (int d = 0; d < 8; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];
            
            if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
            if (v[nx][ny]) continue;
            
            q.push({nx,ny});
            v[nx][ny] = true;
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int l;
        cin >> l;
                
        int si, sj, ei, ej;
        cin >> si >> sj >> ei >> ej;
        
        // 방문 배열 초기화
        memset(v, false, sizeof(v));
        
        // 시작점과 끝점이 같다면 0 출력
        if (si == ei && sj == ej) {
            cout << 0 << '\n';
            continue;
        }
        
        // bfs 호출 및 결과 출력
        cout << bfs(l, si, sj, ei, ej) << '\n';
    }
    return 0;
}
