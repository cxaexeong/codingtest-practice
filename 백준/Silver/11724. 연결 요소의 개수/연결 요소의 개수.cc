#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool vis[1005];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur]) {
            if (vis[nxt]) continue;
            vis[nxt] = true;
            q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m,u,v;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int grp = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            grp++;
            bfs(i);
        }
    }
    cout << grp << '\n';    
}