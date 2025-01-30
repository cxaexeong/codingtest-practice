#include <bits/stdc++.h>
using namespace std;

int n,m,r,c,d,ans;
int board[50][50];
// 북 동 남 서
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            cin >> board[i][j];
    int check = 0;
    while (true) {
        // 청소하지 않은 빈 칸일 경우 청소
        if (board[r][c] == 0) ++ans;
        board[r][c] = -1;        // 청소한 칸이라고 표시
        bool cleaned = false;    // 네 방향 중 청소가 된 곳이 있는지
        for (int i = 0; i < 4; i++) {
            d = (d+3) % 4;
            if (board[r+dx[d]][c+dy[d]] == 0) {
                r += dx[d];
                c += dy[d];
                cleaned = true;
                break;
            }
        }
        if (cleaned) continue;
        // 뒤가 벽으로 막혀있으면 로봇 청소기 종료
        if (board[r-dx[d]][c-dy[d]] == 1)
            break;
        // 막혀 있지 않을 경우, 후진
        r -= dx[d];
        c -= dy[d];
    }
    cout << ans;
}