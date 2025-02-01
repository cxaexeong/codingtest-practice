#include <bits/stdc++.h>
using namespace std;

int n,m;
int board[500][500];
bool v[500][500];
int ans;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void dfs(int x, int y, int depth, int sum) {
    if (depth == 4) {
        ans = max(ans, sum);
        return;
    }
    
    if (!v[y][x]) {
        v[y][x] = true;
        sum += board[y][x];
        
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            
            dfs(nx, ny, depth + 1, sum);
        }
        v[y][x] = false;
    }
    
    // ㅓ 모양
    if (x-1 >= 0 && y-1 >= 0 && y+1<n)
        ans = max(ans, board[y][x] + board[y][x-1] + board[y-1][x] + board[y+1][x]);
    
    // ㅏ 모양
    if (x+1 < m && y-1 >= 0 && y+1<n)
        ans = max(ans, board[y][x] + board[y][x+1] + board[y-1][x] + board[y+1][x]);
    
    // ㅗ 모양
    if (y-1 >= 0 && x-1 >= 0 && x+1 < m)
        ans = max(ans, board[y][x] + board[y-1][x] + board[y][x-1] + board[y][x+1]);
    
    // ㅜ 모양
    if (y+1<n && x-1>=0 && x+1<m)
        ans = max(ans, board[y][x] + board[y+1][x] + board[y][x-1] + board[y][x+1]);
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dfs(j, i, 0, 0);
    
    cout << ans;
}