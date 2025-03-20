#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 20;
const int EMPTY = -2;
const int BLACK = -1;
const int RAINBOW = 0;

int N, M, score = 0;
int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 블록 그룹 찾기
vector<pair<int, int>> find_largest_group() {
    memset(visited, false, sizeof(visited));

    vector<pair<int, int>> best_group;
    int max_size = 0, max_rainbow = 0;
    int best_r = -1, best_c = -1;

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (board[r][c] > 0 && !visited[r][c]) {
                queue<pair<int, int>> q;
                vector<pair<int, int>> group, rainbow_blocks;
                bool temp_visited[MAX_N][MAX_N] = {false};
                
                int color = board[r][c];
                q.push({r, c});
                visited[r][c] = true;
                group.push_back({r, c});

                int rainbow_count = 0, sr = r, sc = c;

                while (!q.empty()) {
                    int x, y;
                    tie(x, y) = q.front(); q.pop();

                    for (int d = 0; d < 4; ++d) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                        if (visited[nx][ny] || board[nx][ny] == BLACK || board[nx][ny] == EMPTY) continue;
                        if (board[nx][ny] == color || board[nx][ny] == RAINBOW) {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                            group.push_back({nx, ny});
                            if (board[nx][ny] == RAINBOW) {
                                rainbow_count++;
                                rainbow_blocks.push_back({nx, ny});
                            } else {
                                if (nx < sr || (nx == sr && ny < sc)) {
                                    sr = nx;
                                    sc = ny;
                                }
                            }
                        }
                    }
                }

                // 무지개 블록은 다른 그룹에서도 사용 가능하도록 방문 해제
                for (auto &p : rainbow_blocks) {
                    visited[p.first][p.second] = false;
                }

                // 블록 그룹 크기가 2 이상이면 고려
                if (group.size() >= 2) {
                    if (group.size() > max_size ||
                        (group.size() == max_size && rainbow_count > max_rainbow) ||
                        (group.size() == max_size && rainbow_count == max_rainbow && (sr > best_r || (sr == best_r && sc > best_c)))) {
                        max_size = group.size();
                        max_rainbow = rainbow_count;
                        best_r = sr;
                        best_c = sc;
                        best_group = group;
                    }
                }
            }
        }
    }

    return best_group;
}

// 블록 그룹 제거
void remove_group(vector<pair<int, int>> &group) {
    for (auto &p : group) {
        board[p.first][p.second] = EMPTY;
    }
    score += group.size() * group.size();
}

// 중력 적용
void apply_gravity() {
    for (int c = 0; c < N; ++c) {
        for (int r = N - 1; r >= 0; --r) {
            if (board[r][c] >= 0) {
                int nr = r;
                while (nr + 1 < N && board[nr + 1][c] == EMPTY) {
                    swap(board[nr][c], board[nr + 1][c]);
                    nr++;
                }
            }
        }
    }
}

// 반시계 90도 회전
void rotate_board() {
    int temp[MAX_N][MAX_N];
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            temp[N - 1 - c][r] = board[r][c];
        }
    }
    memcpy(board, temp, sizeof(board));
}

// 게임 실행
void play_game() {
    while (true) {
        vector<pair<int, int>> largest_group = find_largest_group();
        if (largest_group.empty()) break;

        remove_group(largest_group);
        apply_gravity();
        rotate_board();
        apply_gravity();
    }
}

int main() {
    cin >> N >> M;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> board[r][c];
        }
    }

    play_game();

    cout << score << '\n';
    return 0;
}