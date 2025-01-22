#include <bits/stdc++.h>
using namespace std;

int n, maxBroken = 0;
vector<pair<int, int>> eggs; // {내구도, 무게}

void backtracking(int index) {
    if (index == n) {
        // 현재 상태에서 깨진 계란 수 계산
        int brokenCount = 0;
        for (auto &[durability, weight] : eggs) {
            if (durability <= 0) brokenCount++;
        }
        maxBroken = max(maxBroken, brokenCount);
        return;
    }

    // 현재 계란이 이미 깨졌거나, 칠 수 있는 다른 계란이 없는 경우
    bool canHit = false;
    for (int i = 0; i < n; i++) {
        if (i != index && eggs[i].first > 0 && eggs[index].first > 0) {
            canHit = true;
            break;
        }
    }
    if (!canHit) {
        backtracking(index + 1);
        return;
    }

    // 현재 계란으로 다른 계란 치기
    for (int i = 0; i < n; i++) {
        if (i == index || eggs[i].first <= 0 || eggs[index].first <= 0) continue;

        // 상태 저장
        eggs[index].first -= eggs[i].second;
        eggs[i].first -= eggs[index].second;

        // 다음 단계로 진행
        backtracking(index + 1);

        // 상태 복원
        eggs[index].first += eggs[i].second;
        eggs[i].first += eggs[index].second;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    eggs.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> eggs[i].first >> eggs[i].second; // 내구도와 무게 입력
    }

    backtracking(0);

    cout << maxBroken << '\n';

    return 0;
}
