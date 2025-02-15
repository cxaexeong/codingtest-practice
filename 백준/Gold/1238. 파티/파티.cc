// 파티
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

const int INF = INT_MAX;

int n,m,x;
vector<pair<int,int>> adj[1005], rev_adj[1005];

vector<int> dijkstra(int start, vector<pair<int,int>> graph[]) {
    vector<int> dist(n+1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0,start});

    while (!pq.empty()) {
        auto cur = pq.top(); // first = 현재까지 최단 거리, second = 현재 방문하는 노드
        pq.pop();

        // 이미 더 짧은 거리로 방문한 적 있으면 무시 (중복 방문 방지)
        if (dist[cur.y] < cur.x) continue;

        for (auto nxt : graph[cur.y]) { // nxt.x = weight(가중치), nxt.y = 도착 노드
            // 현재 최단 거리가 더 값이 크면 짧은 거리롤 갱신
            if (dist[nxt.y] > cur.x + nxt.x) {
                dist[nxt.y] = cur.x + nxt.x;    // 최단 거리 갱신
                pq.push({dist[nxt.y], nxt.y}); 
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        rev_adj[v].push_back({w,u});
    }

    vector<int> toX = dijkstra(x, rev_adj); // 모든 마을 -> x까지 최단거리
    vector<int> fromX = dijkstra(x, adj);    // x -> 모든 마을까지 최단거리

    int max_time = 0;
    for (int i = 1; i <= n; i++) {
        max_time = max(max_time, toX[i] + fromX[i]);
    }

    cout << max_time << '\n';
    return 0;
}
