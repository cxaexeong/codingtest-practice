#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char board[5][5];
bool v[5][5]; // 방문 여부를 저장하는 전역 배열
vector<pair<int, int>> selected; // 선택된 칸을 저장하는 전역 벡터
int ans = 0;
#define x first
#define y second

// 선택된 칸이 인접한지 확인(bfs)
bool isConnected() {
    queue<pair<int, int>> q;
    memset(v, false, sizeof(v)); // v 배열 초기화
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
void backtracking(int depth, int sCount, int start) {
    if (depth == 7) {
        if (sCount >= 4 && isConnected()) // 'S' 개수 조건 확인
            ans++;
        return;
    }

    for (int i = start; i < 25; i++) {
        int x = i / 5, y = i % 5;
        selected.push_back({x, y});
        backtracking(depth + 1, sCount + (board[x][y] == 'S'), i + 1);
        selected.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> board[i][j];

    backtracking(0, 0, 0);

    cout << ans << '\n';
    return 0;
}
