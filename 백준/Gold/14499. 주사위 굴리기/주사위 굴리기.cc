#include <iostream>
#include <vector>
using namespace std;

// 주사위와 지도 정의
int dice[6] = {0, 0, 0, 0, 0, 0}; // 윗면, 아랫면, 동쪽, 서쪽, 남쪽, 북쪽
int N, M, x, y, K; // 지도 크기, 초기 위치, 명령 개수
vector<vector<int>> board;

// 주사위를 굴리는 함수
void roll(int dir) {
    int temp[6];
    copy(begin(dice), end(dice), temp); // 현재 주사위 상태 복사

    if (dir == 1) { // 동쪽
        dice[0] = temp[3];
        dice[3] = temp[1];
        dice[1] = temp[2];
        dice[2] = temp[0];
    } else if (dir == 2) { // 서쪽
        dice[0] = temp[2];
        dice[2] = temp[1];
        dice[1] = temp[3];
        dice[3] = temp[0];
    } else if (dir == 3) { // 북쪽
        dice[0] = temp[5];
        dice[5] = temp[1];
        dice[1] = temp[4];
        dice[4] = temp[0];
    } else if (dir == 4) { // 남쪽
        dice[0] = temp[4];
        dice[4] = temp[1];
        dice[1] = temp[5];
        dice[5] = temp[0];
    }
}

// 명령을 수행하는 함수
void execute(int dir) {
    int nx = x, ny = y;

    // 이동 방향에 따른 좌표 변화
    if (dir == 1) ny++;     // 동쪽
    else if (dir == 2) ny--;// 서쪽
    else if (dir == 3) nx--;// 북쪽
    else if (dir == 4) nx++;// 남쪽

    // 범위를 벗어나면 무시
    if (nx < 0 || ny < 0 || nx >= N || ny >= M) return;

    // 위치 갱신 및 주사위 굴리기
    x = nx, y = ny;
    roll(dir);

    // 지도와 주사위 아랫면 동기화
    if (board[x][y] == 0) {
        board[x][y] = dice[1]; // 주사위 아랫면 값 복사
    } else {
        dice[1] = board[x][y]; // 칸의 값 복사
        board[x][y] = 0;       // 칸 초기화
    }

    // 윗면 출력
    cout << dice[0] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    cin >> N >> M >> x >> y >> K;
    board.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    vector<int> commands(K);
    for (int i = 0; i < K; i++) {
        cin >> commands[i];
    }

    // 명령 실행
    for (int dir : commands) {
        execute(dir);
    }

    return 0;
}
