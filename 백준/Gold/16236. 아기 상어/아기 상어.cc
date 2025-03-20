#include <bits/stdc++.h>
using namespace std;

int N;
int board[22][22];
int dist[22][22]; // BFS 탐색 거리 저장
bool visited[22][22];

int bs_size = 2;   // 아기 상어 크기
int eat_count = 0; // 먹은 물고기 수
int shark_time = 0; // 총 이동 거리(시간)

int dx[4] = {-1, 0, 1, 0}; // 상좌하우 (거리 우선순위 고려)
int dy[4] = {0, -1, 0, 1};

// BFS로 가장 가까운 먹을 수 있는 물고기 탐색
pair<int, int> bfs(pair<int, int> babyshark) {
    memset(visited, false, sizeof(visited));
    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> q;
    q.push(babyshark);
    visited[babyshark.first][babyshark.second] = true;
    dist[babyshark.first][babyshark.second] = 0;

    vector<pair<int, int>> fish_list; // 먹을 수 있는 물고기 목록
    int min_dist = INT_MAX; // 가장 가까운 물고기 거리

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue; // 범위 벗어나면 패스
            if (visited[nx][ny] || board[nx][ny] > bs_size) continue; // 이미 방문했거나, 못 지나가는 경우 패스

            visited[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});

            if (board[nx][ny] > 0 && board[nx][ny] < bs_size) { // 먹을 수 있는 물고기 찾기
                if (dist[nx][ny] < min_dist) {
                    min_dist = dist[nx][ny];
                    fish_list.clear(); // 더 가까운 물고기가 있으면 기존 목록 삭제
                    fish_list.push_back({nx, ny});
                } 
                else if (dist[nx][ny] == min_dist) {
                    fish_list.push_back({nx, ny}); // 같은 거리면 후보 추가
                }
            }
        }
    }

    if (fish_list.empty()) return {-1, -1}; // 먹을 수 있는 물고기 없음

    // 가장 위쪽, 왼쪽에 있는 물고기 선택
    sort(fish_list.begin(), fish_list.end());
    return fish_list[0]; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    pair<int, int> babyshark;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                babyshark = {i, j};
                board[i][j] = 0; // 상어 위치는 0으로 변경
            }
        }
    }

    while (true) {
        pair<int, int> target = bfs(babyshark);
        if (target.first == -1) break; // 더 이상 먹을 물고기가 없으면 종료

        // 이동 시간 추가
        shark_time += dist[target.first][target.second];

        // 상어 위치 갱신
        babyshark = target;

        // 물고기 먹기
        board[target.first][target.second] = 0;
        eat_count++;

        // 크기 증가 조건 확인
        if (eat_count == bs_size) {
            bs_size++;
            eat_count = 0;
        }
    }

    cout << shark_time << '\n'; // 총 이동 시간 출력
    return 0;
}
