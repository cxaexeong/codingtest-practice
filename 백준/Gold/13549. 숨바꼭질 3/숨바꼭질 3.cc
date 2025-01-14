#include <bits/stdc++.h>
int dist[100002];
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    fill(dist, dist + 100002, -1);

    deque<int> dq;
    dq.push_back(n);
    dist[n] = 0;

    while (!dq.empty()) {
        int c = dq.front();
        dq.pop_front();

        if (c == k) {
            cout << dist[k];
            return 0;
        }

        // 순간 이동
        if (c * 2 <= 100000 && dist[c * 2] == -1) {
            dist[c * 2] = dist[c];
            dq.push_front(c * 2);
        }

        // 일반 이동 (뒤로 한 칸 이동)
        if (c - 1 >= 0 && dist[c - 1] == -1) {
            dist[c - 1] = dist[c] + 1;
            dq.push_back(c - 1);
        }

        // 일반 이동 (앞으로 한 칸 이동)
        if (c + 1 <= 100000 && dist[c + 1] == -1) {
            dist[c + 1] = dist[c] + 1;
            dq.push_back(c + 1);
        }
    }
}
