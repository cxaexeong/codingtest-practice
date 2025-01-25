#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int n, m;
int board[50][50];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { 
            cin >> board[i][j];
            if (board[i][j] == 1) house.push_back({i, j});
            if (board[i][j] == 2) chicken.push_back({i, j});
        }
    }

    // 치킨집 선택 여부를 나타내는 벡터
    vector<int> brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin() + chicken.size() - m, 0); // 앞쪽은 0, 뒤쪽은 1로 초기화

    int mn = INT_MAX; // 최소 치킨 거리 초기화

    // 가능한 모든 조합 탐색
    do {
        int dist = 0;
        for (auto h : house) {
            int tmp = INT_MAX;
            for (int i = 0; i < chicken.size(); i++) {
                if (brute[i] == 0) continue; // 선택되지 않은 치킨집은 건너뜀
                tmp = min(tmp, abs(chicken[i].x - h.x) + abs(chicken[i].y - h.y));
            }
            dist += tmp; // 집별 최소 치킨 거리 누적
        }
        mn = min(mn, dist); // 최소 치킨 거리 갱신
    } while (next_permutation(brute.begin(), brute.end()));

    cout << mn; // 결과 출력
}
