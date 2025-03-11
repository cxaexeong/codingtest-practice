#include <bits/stdc++.h>
using namespace std;

int n;
int board[22][22];
bool team[22];  // true: 스타트 팀, false: 링크 팀
int minDiff = INT_MAX;  // 최소 능력치 차이 저장

void dfs(int idx, int cnt) {
    if (cnt == n / 2) {  // 팀이 반씩 나뉘었을 때
        vector<int> start, link;
        for (int i = 0; i < n; i++) {
            if (team[i]) start.push_back(i);
            else link.push_back(i);
        }

        int startPower = 0, linkPower = 0;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                if (i == j) continue;
                startPower += board[start[i]][start[j]];
                linkPower += board[link[i]][link[j]];
            }
        }

        minDiff = min(minDiff, abs(startPower - linkPower));
        return;
    }

    for (int i = idx; i < n; i++) {
        if (!team[i]) {
            team[i] = true;
            dfs(i + 1, cnt + 1);
            team[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    dfs(0, 0);
    cout << minDiff << '\n';

    return 0;
}
