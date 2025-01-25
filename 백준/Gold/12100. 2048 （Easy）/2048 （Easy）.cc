#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int n;
int board1[22][22];
int board2[22][22];

void rotate() {
    int tmp[22][22];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = board2[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board2[i][j] = tmp[n - 1 - j][i];
}

void tilt(int dir) {
    while (dir--) rotate();
    for (int i = 0; i < n; i++) {
        int tilted[22] = {}; // board2를 왼쪽으로 기울인 결과를 저장할 배열
        int idx = 0;         // tilted 배열에서 어디 삽입해야 하는지 가리키는 변수
        for (int j = 0; j < n; j++) {
            if (board2[i][j] == 0) continue;
            if (tilted[idx] == 0) {
                tilted[idx] = board2[i][j];
            } else if (tilted[idx] == board2[i][j]) {
                tilted[idx++] *= 2;
            } else {
                tilted[++idx] = board2[i][j];
            }
        }
        for (int j = 0; j < n; j++) 
            board2[i][j] = tilted[j];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board1[i][j];
    
    int mx = 0;
    for (int tmp = 0; tmp < 1024; tmp++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board2[i][j] = board1[i][j];
        int brute = tmp;
        for (int d = 0; d < 5; d++) {
            int dir = brute % 4;
            brute /= 4;
            tilt(dir);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mx = max(mx, board2[i][j]);
    }
    cout << mx;    
}
