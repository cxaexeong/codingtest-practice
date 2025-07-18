#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        int K;
        cin >> K;

        // 최소 비용을 저장하는 map (value -> cost)
        unordered_map<int, int> dist;

        // min-heap: {누적비용, 현재값}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, K});
        dist[K] = 0;

        while (!pq.empty()) {
            int cost = pq.top().first;
            int value = pq.top().second;
            pq.pop();

            if (value == 0) {
                break;
            }

            // 같은 값이라도 더 나은 경로가 있다면 continue
            if (dist[value] < cost) continue;

            for (int i = 0; i < N; i++) {
                int next_value = value / arr[i];
                int next_cost = cost + (value % arr[i]);

                if (dist.find(next_value) == dist.end() || next_cost < dist[next_value]) {
                    dist[next_value] = next_cost;
                    pq.push({next_cost, next_value});
                }
            }
        }

        cout << "#" << t << " " << dist[0] << '\n';
    }

    return 0;
}
