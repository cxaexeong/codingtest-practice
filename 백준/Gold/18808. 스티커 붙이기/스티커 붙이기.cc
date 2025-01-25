#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int note[42][42];
int sticker[12][12];
int n,m,k;
int r,c;

void rotate() {
    int tmp[12][12];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            tmp[i][j] = sticker[i][j];
    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            sticker[i][j] = tmp[r-1-j][i];
    swap(r,c);
}

bool pastable(int x, int y) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            if (x + i >= n || y + j >= m) return false;
            if (note[x+i][y+j] == 1 && sticker[i][j] == 1) 
                return false;
        }
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (sticker[i][j] == 1)
                note[x+i][y+j] = 1;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    while (k--) {
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> sticker[i][j];
        
        bool is_paste = false;
        for (int rotation = 0; rotation < 4; rotation++) {
            for (int x = 0; x <= n - r; x++) {
                if (is_paste) break;
                for (int y = 0; y <= m - c; y++) {
                    if (pastable(x, y)) {
                        is_paste = true;
                        break;
                    }
                }
            }
            if (is_paste) break;
            rotate();
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cnt += note[i][j];
    cout << cnt << '\n';
}
