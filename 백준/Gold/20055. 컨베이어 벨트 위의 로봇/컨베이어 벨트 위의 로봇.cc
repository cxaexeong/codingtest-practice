#include <bits/stdc++.h>
using namespace std;

int n, k;
deque<int> durability; // 벨트 내구도
deque<bool> robots;    // 로봇 존재 여부 (크기 n)
int step = 0;          // 단계 수

// ✅ 내구도가 0인 칸 개수 확인
int count_zero() {
    return count(durability.begin(), durability.end(), 0);
}

// ✅ 컨베이어 벨트 회전
void rotate_belt() {
    durability.push_front(durability.back());
    durability.pop_back();

    // 로봇도 함께 회전 (🚨 push_front 사용)
    robots.push_front(robots.back());
    robots.pop_back();

    // 로봇이 내리는 위치에서 제거
    robots[n - 1] = false;
}

// ✅ 로봇 이동
void move_robots() {
    for (int i = n - 2; i >= 0; i--) { // 뒤에서부터 이동
        if (robots[i] && !robots[i + 1] && durability[i + 1] > 0) {
            robots[i] = false;
            robots[i + 1] = true;
            durability[i + 1]--;
        }
    }
    // 🚨 로봇이 내리는 위치에서 제거해야 함
    robots[n - 1] = false;
}

// ✅ 로봇 올리기
void put_robot() {
    if (durability[0] > 0) {
        robots[0] = true;
        durability[0]--;
    }
}

// ✅ 시뮬레이션 실행
int solve() {
    while (count_zero() < k) {
        step++;
        // 1. 벨트 회전
        rotate_belt();
        // 2. 로봇 이동
        move_robots();
        // 3. 새 로봇 올리기
        put_robot();
    }
    return step;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    durability.resize(2 * n);
    robots.resize(n, false); // 🚨 크기 n으로 수정

    for (int i = 0; i < 2 * n; i++) cin >> durability[i];

    cout << solve() << '\n';
    return 0;
}
