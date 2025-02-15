#include <bits/stdc++.h>
using namespace std;

int n, m, st, en;
int dist[1005], pre[1005];  // 최단 거리 저장 및 경로 추적 배열
const int INF = 1e9;
vector<pair<int, int>> adj[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;  // 입력 변수 수정
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    cin >> st >> en;
    
    fill(dist, dist + n + 1, INF);
    dist[st] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, st});
    
    while (!pq.empty()) {
        int cur_dist, cur_node;
        tie(cur_dist, cur_node) = pq.top();
        pq.pop();
        
        if (dist[cur_node] < cur_dist) continue;
        
        for (auto nxt : adj[cur_node]) {
            int weight = nxt.first;
            int nxt_node = nxt.second;
            int new_dist = cur_dist + weight;

            if (new_dist < dist[nxt_node]) {
                dist[nxt_node] = new_dist;
                pq.push({new_dist, nxt_node});
                pre[nxt_node] = cur_node;
            }
        }
    }
    
    // 최단 거리 출력
    cout << dist[en] << '\n';

    // 최단 경로 추적
    vector<int> path;
    int cur = en;
    while (cur != st) {
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);
    
    reverse(path.begin(), path.end());

    cout << path.size() << '\n';
    for (auto x : path) cout << x << ' ';
    
    return 0;
}
