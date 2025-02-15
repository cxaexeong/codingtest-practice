// 최소 비용2
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second    

int v, e, st, en;

vector<pair<int,int>> adj[1005];
const int INF = INT_MAX;
int pre[1005];
int dist[1005];    // 최단거리 테이블

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

     cin >> v >> e;
     fill(dist, dist+v+1, INF);

     while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
     }
     cin >> st >> en;

     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
     dist[st] = 0;

     // 우선순위 큐 (0, 시작점) 추가
     pq.push({0,st});
     while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        
        if (dist[cur.y] < cur.x) continue;

        for (auto nxt : adj[cur.y]) {
         if (dist[nxt.y] <= dist[cur.y] + nxt.x) continue;
         dist[nxt.y] = dist[cur.y] + nxt.x;
         pq.push({dist[nxt.y], nxt.y});
         pre[nxt.y] = cur.y;
        }
     }
     cout << dist[en] << '\n';
     vector<int> path;
     int cur = en;
     while (cur != st) {
      path.push_back(cur);
      cur = pre[cur];
     }
     path.push_back(cur);
     reverse(path.begin(), path.end());
     cout << path.size() << '\n';
     for (auto x: path) cout << x << ' ';

}