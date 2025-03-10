#include <bits/stdc++.h>
using namespace std;

int n,k;
deque<int> durability;
deque<bool> robots;
int step = 0;

int count_zero() {
    return count(durability.begin(), durability.end(), 0);
}

void rotate_belt() {
    durability.push_front(durability.back());
    durability.pop_back();

    robots.push_front(robots.back());
    robots.pop_back();
    robots[n-1] = false;
}

void move_robots() {
    for (int i = n - 2; i >= 0; i--) {
        if (robots[i] && !robots[i+1] && durability[i+1] >= 1) {
            robots[i] = false;
            robots[i+1] = true;
            durability[i+1]--;
        }
    }
    robots[n-1] = false;
}

void put_robots() {
    if (durability[0] > 0) {
        robots[0] = true;
        durability[0]--;
    }
}

int solve() {
    while (count_zero() < k) {
        step++;
        // 1. 벨트 회전
        rotate_belt();
        // 2. 로봇 함께 회전
        move_robots();
        // 3. 새 로봇 올리기
        put_robots();
    }
    return step;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    durability.resize(2*n);
    robots.resize(n, false);
    
    for (int i = 0; i < 2 * n; i++) cin >> durability[i];

    cout << solve() << '\n';
    return 0;
}
