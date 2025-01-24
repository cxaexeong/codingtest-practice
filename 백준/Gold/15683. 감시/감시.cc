#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int board1[10][10];
int board2[10][10];
int n, m;
vector<pair<int, int>> cctv;

void upd(int x, int y, int dir) {
    dir %= 4;
    while (true) {
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x >= n || y < 0 || y >= m || board2[x][y] == 6) return;
        if (board2[x][y] != 0) continue;
        board2[x][y] = 7;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int mn = n*m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) { // 수정: j < m
            cin >> board1[i][j];
            if (board1[i][j] != 0 && board1[i][j] != 6)
                cctv.push_back({i, j});
        }
    for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++) {
        memcpy(board2, board1, sizeof(board1));
        int brute = tmp;

        for (int i = 0; i < cctv.size(); i++) {
            int dir = brute % 4;
            brute /= 4;
            int x = cctv[i].x;
            int y = cctv[i].y;

            if (board1[x][y] == 1)
                upd(x, y, dir);
            else if (board1[x][y] == 2) {
                upd(x, y, dir);
                upd(x, y, dir + 2);
            } else if (board1[x][y] == 3) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
            } else if (board1[x][y] == 4) {
                upd(x, y, dir);
                upd(x, y, dir + 1);
                upd(x, y, dir + 2);
            } else if (board1[x][y] == 5) {
                for (int d = 0; d < 4; d++)
                    upd(x, y, dir + d); // 수정: dir + d
            }
        }
        int val = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) // 수정: j < m
                if (board2[i][j] == 0) val++; // 수정: board2
        mn = min(val, mn);
    }
    cout << mn;
}
