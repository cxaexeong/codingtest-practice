#include <bits/stdc++.h>
using namespace std;

int n, l;
int board[102][102];
int cnt = 0; // 지나갈 수 있는 길의 개수

bool canPass(vector<int>& line) {
    vector<bool> used(n, false);  // 경사로 설치 여부

    for (int i = 0; i < n - 1; i++) {
        if (line[i] == line[i + 1]) continue;  // 높이가 같으면 진행
        
        if (abs(line[i] - line[i + 1]) > 1) return false;  // 높이 차이가 1보다 크면 불가능

        // 높이가 증가하는 경우 (왼쪽에 경사로 설치)
        if (line[i] < line[i + 1]) {
            for (int j = 0; j < l; j++) {
                if (i - j < 0 || line[i - j] != line[i] || used[i - j]) return false;
                used[i - j] = true;
            }
        }
        // 높이가 감소하는 경우 (오른쪽에 경사로 설치)
        else {
            for (int j = 0; j < l; j++) {
                if (i + 1 + j >= n || line[i + 1 + j] != line[i + 1] || used[i + 1 + j]) return false;
                used[i + 1 + j] = true;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // 가로 방향 검사
    for (int i = 0; i < n; i++) {
        vector<int> row(board[i], board[i] + n);
        if (canPass(row)) cnt++;
    }

    // 세로 방향 검사
    for (int j = 0; j < n; j++) {
        vector<int> col;
        for (int i = 0; i < n; i++) {
            col.push_back(board[i][j]);
        }
        if (canPass(col)) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}
