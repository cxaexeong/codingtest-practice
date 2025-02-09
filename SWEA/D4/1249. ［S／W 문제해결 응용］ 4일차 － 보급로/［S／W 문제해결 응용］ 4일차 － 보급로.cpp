#include <iostream>
#include <queue>
#include <vector>
#include <climits>  // INT_MAX 사용

#define x first
#define y second

using namespace std;

int n;
int board[101][101];
int dist[101][101];  // 최단 경로 비용 저장 배열
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// BFS로 최소 복구 시간 찾기
int bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = board[0][0]; // 시작점 비용 초기화

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            // 새로운 비용 계산
            int newCost = dist[cur.x][cur.y] + board[nx][ny];

            // 더 작은 비용이면 갱신하고 큐에 추가
            if (newCost < dist[nx][ny]) {
                dist[nx][ny] = newCost;
                q.push({nx, ny});
            }
        }
    }
    return dist[n - 1][n - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        cin >> n;

        // 입력 받기 및 결과 배열 초기화
        for (int i = 0; i < n; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < n; j++) {
                board[i][j] = row[j] - '0';  // 숫자로 변환
                dist[i][j] = INT_MAX;      // 초기화
            }
        }

        int answer = bfs();
        cout << "#" << t << " " << answer << '\n';
    }
    return 0;
}
