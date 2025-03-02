#include <bits/stdc++.h>
using namespace std;

int n, m, start, u, v;
vector<int> adj[1005];
bool vis[1005];

void dfs(int cur) {
    cout << cur << '\n';
    vis[cur] = true;

    for (int nxt : adj[cur]) {
        if (!vis[nxt]) {
            dfs(nxt);
        }
    }
}

void bfs(int cur) {
    queue<int> q;
    q.push(cur);
    vis[cur] = true;

    while (!q.empty()) {
        int c = q.front(); q.pop();
        cout << c << '\n';

        for (int nxt : adj[c]) {
            if (!vis[nxt]) {
                vis[nxt] = true;
                q.push(nxt);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> start;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    
    dfs(start);

    fill(vis, vis+1005, false);
    bfs(start);

    return 0;
}