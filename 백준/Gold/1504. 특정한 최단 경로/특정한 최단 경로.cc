#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;

int n, e;
vector<pair<int, int>> adj[805];
int dist[805]; 

// 다익스트라 알고리즘 (start에서 end까지 최단 거리)
ll dijkstra(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    fill(dist, dist + n + 1, INF);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur_dist, cur_node;
        tie(cur_dist, cur_node) = pq.top();
        pq.pop();

        if (dist[cur_node] < cur_dist) continue;

        for (auto nxt : adj[cur_node]) {
            int weight, nxt_node;
            tie(weight, nxt_node) = nxt;
            int new_dist = cur_dist + weight;

            if (new_dist < dist[nxt_node]) {
                dist[nxt_node] = new_dist;
                pq.push({new_dist, nxt_node});
            }
        }
    }
    return dist[end];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int v1, v2;
    cin >> v1 >> v2;

    // 1 → v1 → v2 → n 경로
    ll path1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n);

    // 1 → v2 → v1 → n 경로
    ll path2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, n);

    // 최소 경로 선택
    ll result = min(path1, path2);

    // 경로가 없을 경우 -1 출력
    if (result >= INF) result = -1;

    cout << result << '\n';
    return 0;
}
