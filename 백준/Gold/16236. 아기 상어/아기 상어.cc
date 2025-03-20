#include <bits/stdc++.h>
using namespace std;

int N;
int board[22][22];
int dist[22][22]; // BFS 탐색 거리 저장
bool visited[22][22];

int bs_size = 2;   // 아기 상어 크기
int eat_count = 0; // 먹은 물고기 수
int shark_time = 0; // 총 이동 거리(시간)

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

pair<int,int> bfs(pair<int,int> babyshark) {
    memset(visited, false, sizeof(visited));
    memset(dist, -1, sizeof(dist));

    queue<pair<int,int>> q;
    q.push(babyshark); 
    visited[babyshark.first][babyshark.second] = true;
    dist[babyshark.first][babyshark.second] = 0;

    int mn_dist = INT_MAX;
    vector<pair<int, int>> eatList; // 먹을 수 있는 물고기 리스트 

    while (!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny] || board[nx][ny] > bs_size) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;

            if (board[nx][ny] > 0 && board[nx][ny] < bs_size) {
                if (dist[nx][ny] < mn_dist) {
                    mn_dist = dist[nx][ny];
                    eatList.clear();    // 더 가까운 물고기가 있으면 기존 목록 삭제
                    eatList.push_back({nx, ny});
                } else if (dist[nx][ny] == mn_dist) {
                    eatList.push_back({nx, ny});    // 같은 거리면 후보 추가
                }
            }
        }
    }
    if (eatList.empty()) return {-1, -1};   // 먹을 수 있는 물고기 없음
    // 가장 위쪽, 왼쪽에 있는 물고기 선택
    sort(eatList.begin(), eatList.end());
    return eatList[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    pair<int,int> babyshark;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                babyshark = {i, j};
                board[i][j] = 0;
            }
        }
    }
    
    while (1) {
        pair<int, int> target = bfs(babyshark);
        if (target.first == -1) break;

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
    cout << shark_time << '\n';
    return 0;
}
