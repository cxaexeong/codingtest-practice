#include <bits/stdc++.h>
using namespace std;

int n, m, x;
const int INF = 1e9;
vector<pair<int,int>> adj[1005], rev_adj[1005];

vector<int> dijkstra(int start, vector<pair<int,int>> graph[]) {
    vector<int> dist(n+1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    
    dist[start] = 0;
    pq.push({0,start});
    
    while (!pq.empty()) {
        int cur_dist, cur_node; // 현재까지 최단거리, 현재까지 방문한 노드
        tie(cur_dist, cur_node) = pq.top();
        pq.pop();
        
        if (dist[cur_node] < cur_dist) continue;
        
        for (auto nxt : graph[cur_node]) {
            int weight = nxt.first;
            int nxt_node = nxt.second;
            int new_dist = cur_dist + weight;
            if (new_dist < dist[nxt_node]) {
                dist[nxt_node] = new_dist;
                pq.push({new_dist, nxt_node});
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
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        rev_adj[v].push_back({w,u});
    }
    
    vector<int> toX = dijkstra(x, adj); 
    vector<int> fromX = dijkstra(x, rev_adj); 
    
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, toX[i] + fromX[i]);
    }
    
    cout << mx << '\n';
    return 0;   
}