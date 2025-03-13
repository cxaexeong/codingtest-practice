#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 11;
const int MAX_H = 31;

int N, M, H;
bool ladder[MAX_H][MAX_N];  // ladder[h][n]: h번째 높이에 n번째 세로선에서 오른쪽으로 연결되어 있는지
int answer = 4;  // 4 이상은 불가능하므로 4로 초기화

// 사다리 타기 결과가 올바른지 확인하는 함수
bool check() {
    for (int i = 1; i <= N; ++i) {
        int pos = i;
        for (int h = 1; h <= H; ++h) {
            if (ladder[h][pos]) pos++;       // 오른쪽 이동
            else if (pos > 1 && ladder[h][pos - 1]) pos--;  // 왼쪽 이동
        }
        if (pos != i) return false;  // i번 세로선이 i번으로 끝나지 않으면 실패
    }
    return true;
}

// 백트래킹: 현재 depth에서 최대 3개까지 가로선을 추가하며 탐색
void dfs(int depth, int x, int y) {
    if (depth >= answer) return;  // 이미 최소값보다 크면 탐색 불필요
    if (check()) {
        answer = depth;
        return;
    }
    if (depth == 3) return;  // 최대 3개까지만 추가 가능

    for (int h = x; h <= H; ++h) {
        for (int n = (h == x ? y : 1); n < N; ++n) {
            if (!ladder[h][n] && !ladder[h][n - 1] && !ladder[h][n + 1]) {
                ladder[h][n] = true;
                dfs(depth + 1, h, n);
                ladder[h][n] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> H;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;
    }

    dfs(0, 1, 1);

    cout << (answer > 3 ? -1 : answer) << "\n";
    return 0;
}
