#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[505];
bool visited[505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<pair<int, int>> q; // {현재 노드, depth}
    visited[1] = true;       // 방문 표시
    q.push({1, 0});
    
    int cnt = 0;
    
    while (!q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if (depth >= 2) continue;
        
        for (int nxt : adj[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true; // 방문 처리
                q.push({nxt, depth + 1});
                cnt++;
            } 
        }
    }

    cout << cnt << '\n'; // 초대할 사람 수 출력
    return 0;
}
