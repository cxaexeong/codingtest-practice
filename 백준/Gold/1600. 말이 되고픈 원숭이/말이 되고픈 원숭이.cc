#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

struct state {
    int x, y, k, dist;
};

int main() {
    int k, w, h;
    cin >> k >> w >> h;

    // board는 w x h 크기의 2D 배열, 0으로 초기화
    // board = [
    //[0, 0, 0, 0],
    //[0, 0, 0, 0],
    //[0, 0, 0, 0],
    //[0, 0, 0, 0]
    //];
    vector<vector<int>> board(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> board[i][j];
        }
    }

    // v는 3D 배열로 초기화, h x w x (k+1)
    vector<vector<vector<bool>>> v(h, vector<vector<bool>>(w, vector<bool>(k + 1, false)));

    // 일반 이동 (4방향)
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    // 말 이동 (8방향)
    int horse_dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int horse_dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

    // q는 state 구조체를 저장하는 빈 큐로 초기화: q.push({0, 0, 0, 0}); // (x, y, k, dist)
    // 결과 : q = [{x: 0, y: 0, k: 0, dist: 0}]
    queue<state> q;
    q.push({0, 0, 0, 0});
    v[0][0][0] = true;

    while (!q.empty()) {
        state cur = q.front();
        q.pop();

        if (cur.x == h - 1 && cur.y == w - 1) {
            cout << cur.dist << "\n";
            return 0;
        }

        // 일반 이동
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < h && ny < w && !v[nx][ny][cur.k] && board[nx][ny] == 0) {
                v[nx][ny][cur.k] = true;
                q.push({nx, ny, cur.k, cur.dist + 1});
            }
        }

        // 말 이동
        if (cur.k < k) {
            for (int i = 0; i < 8; ++i) {
                int nx = cur.x + horse_dx[i];
                int ny = cur.y + horse_dy[i];

                if (nx >= 0 && ny >= 0 && nx < h && ny < w && !v[nx][ny][cur.k + 1] && board[nx][ny] == 0) {
                    v[nx][ny][cur.k + 1] = true;
                    q.push({nx, ny, cur.k + 1, cur.dist + 1});
                }
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}
