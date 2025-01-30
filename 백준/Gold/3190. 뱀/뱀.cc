#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int n, k, l;
int board[101][101]; // 0: 빈 칸, 1: 사과, 2: 뱀
vector<pair<int, char>> turns; // 방향 변환 정보 저장

// 우, 하, 좌, 상 → 오른쪽 기준 시계 방향
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int simulate() {
    deque<pair<int, int>> snake; // 뱀의 몸 (deque 사용)
    snake.push_back({1, 1}); // 뱀의 초기 위치
    board[1][1] = 2; // 뱀 표시
    int time = 0, dir = 0; // 시작 시간, 현재 방향(오른쪽)

    while (true) {
        time++;

        // 1. 머리 이동
        int nx = snake.front().x + dx[dir];
        int ny = snake.front().y + dy[dir];

        // 2. 벽 or 자기자신과 충돌 시 종료
        if (nx <= 0 || nx > n || ny <= 0 || ny > n || board[nx][ny] == 2)
            return time;

        // 3. 이동한 칸이 사과가 있는 경우
        if (board[nx][ny] == 1) {
            board[nx][ny] = 2; // 머리 추가
            snake.push_front({nx, ny});
        }

        // 4. 이동한 칸이 빈 칸인 경우
        else {
            board[nx][ny] = 2;
            snake.push_front({nx, ny});
            // 꼬리 제거
            int tx = snake.back().x;
            int ty = snake.back().y;
            board[tx][ty] = 0;
            snake.pop_back();
        }

        // 5. 방향 전환 체크
        if (!turns.empty() && time == turns.front().x) {
            if (turns.front().y == 'L')
                dir = (dir + 3) % 4; // 왼쪽 회전
            else
                dir = (dir + 1) % 4; // 오른쪽 회전
            turns.erase(turns.begin());
        }
    }
    return time;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> k;
    
    int r, c, x;
    char d;
    
    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        board[r][c] = 1; // 사과 위치 저장
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> x >> d;
        turns.push_back({x, d});
    }

    cout << simulate();
}
