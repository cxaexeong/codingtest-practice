#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char board[5][5];
int ans = 0;
#define x first
#define y second

// 선택된 칸이 인접한지 확인(bfs)
bool isConnected(vector<pair<int, int>> &selected) {
    queue<pair<int, int>> q;
    vector<vector<bool>> v(5, vector<bool>(5, false));
    int count = 1;

    q.push(selected[0]);
    v[selected[0].x][selected[0].y] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;

            for (auto &[sx, sy] : selected) {
                if (nx == sx && ny == sy && !v[nx][ny]) {
                    v[nx][ny] = true;
                    q.push({nx, ny});
                    count++;
                }
            }
        }
    }
    return count == 7; // 선택된 7개의 칸이 모두 연결되었는지 확인
}

// 칸 7개를 선택하는 조합 생성
void backtracking(int depth, int sCount, vector<pair<int, int>> &selected, int start) {
    if (depth == 7) {
        if (sCount >= 4 && isConnected(selected)) // 'S' 개수 조건 수정
            ans++;
        return;
    }

    for (int i = start; i < 25; i++) {
        int x = i / 5, y = i % 5;
        selected.push_back({x, y});
        backtracking(depth + 1, sCount + (board[x][y] == 'S'), selected, i + 1);
        selected.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> board[i][j];

    vector<pair<int, int>> selected;
    backtracking(0, 0, selected, 0);

    cout << ans << '\n';
    return 0;
}
