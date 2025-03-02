#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10005];
bool visited[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int ans = 0;
    
    queue<pair<int,int>> q; // {현재 노드, 깊이}
    q.push({1,0});
    visited[1] = true;
    
    while (!q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if (depth >= 2) continue; 
        
        for (int nxt : adj[cur]) {
            if (visited[nxt]) continue;
            q.push({nxt, depth+1});
            visited[nxt] = true;
            ans++;
        }
    }
    cout << ans << '\n';
}