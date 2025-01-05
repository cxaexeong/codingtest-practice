#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int board[502][502]; // 1이 파란 칸, 0이 빨간 칸
bool v[502][502];
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    int mx = 0;  // 그림의 최대값
    int num = 0; // 그림의 수
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) { 
            if (board[i][j] == 0 || v[i][j]) continue; // 해당 칸이 색칠 안된 부분이거나 이미 (i,j)를 방문했을 경우 넘어감
            num++; // 그림의 수 증가
            queue<pair<int,int>> q; // pait -> pair로 수정
            v[i][j] = 1; // (i,j)로 bfs 시작 및 방문 표시
            q.push({i,j});
            
            int area = 0; // 그림의 넓이
            while (!q.empty()) {
                area++; // 큐에 들어있는 원소를 하나 뺄 때마다 넓이 1 증가
                pair<int,int> cur = q.front();
                q.pop();
                
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖
                    if(v[nx][ny] || board[nx][ny] != 1) continue;        // 이미 방문 칸 or 파란칸x
                    v[nx][ny] = 1; // 방문 표시
                    q.push({nx,ny});
                }
            }
            mx = max(mx, area); 
        }
    cout << num << '\n' << mx;
}
