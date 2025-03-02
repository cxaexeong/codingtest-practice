#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105];
bool visited[105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, num, u, v;
    cin >> n >> num;
    
    for (int i = 1; i <= num; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int virus = 0;
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        
        for (int nxt : adj[cur]) {
            if (visited[nxt]) continue;  // ✅ 방문한 경우 건너뛴다.
            q.push(nxt);
            visited[nxt] = true;
            virus++;
        }
    }
    
    cout << virus << '\n';  // ✅ 감염된 컴퓨터 개수 출력
}
