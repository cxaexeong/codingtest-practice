#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define INF INT_MAX

int v, e, st;
vector<pair<int,int>> adj[20005];    // {비용, 정점번호}
int dist[20005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> v >> e >> st;
    fill(dist, dist + v + 1, INF);
    
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[st] = 0;
    pq.push({0, st}); // 시작점을 큐에 추가

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop(); // pop() 추가

        if (dist[cur.y] != cur.x) continue;

        for (auto nxt : adj[cur.y]) {
            if (dist[nxt.y] <= dist[cur.y] + nxt.x) continue;
            dist[nxt.y] = dist[cur.y] + nxt.x;
            pq.push({dist[nxt.y], nxt.y});
        }
    }
    
    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}
