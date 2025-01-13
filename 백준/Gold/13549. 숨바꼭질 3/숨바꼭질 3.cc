#include <bits/stdc++.h>
using namespace std;

int dist[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    fill(dist, dist + 100001, -1); // 거리 배열 초기화
    deque<int> dq;
    dq.push_back(n);
    dist[n] = 0;

    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        // 목표 지점에 도달한 경우
        if (cur == k) {
            cout << dist[cur];
            return 0;
        }

        // 순간이동 (시간 0)
        if (cur * 2 <= 100000 && dist[cur * 2] == -1) {
            dist[cur * 2] = dist[cur];
            dq.push_front(cur * 2); // 앞쪽에 삽입
        }

        // 뒤로 한 칸 이동 (시간 1)
        if (cur - 1 >= 0 && dist[cur - 1] == -1) {
            dist[cur - 1] = dist[cur] + 1;
            dq.push_back(cur - 1); // 뒤쪽에 삽입
        }

        // 앞으로 한 칸 이동 (시간 1)
        if (cur + 1 <= 100000 && dist[cur + 1] == -1) {
            dist[cur + 1] = dist[cur] + 1;
            dq.push_back(cur + 1); // 뒤쪽에 삽입
        }
    }
}
