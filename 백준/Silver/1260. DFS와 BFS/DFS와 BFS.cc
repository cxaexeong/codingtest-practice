#include <bits/stdc++.h>
using namespace std;

int n, m, start, u, v;
vector<int> adj[1005];
bool vis[1005];

// ✅ DFS 함수 (재귀 버전)
void dfs(int cur) {
    cout << cur << ' '; // 방문한 노드 출력
    vis[cur] = true;
    
    for (int nxt : adj[cur]) { // 인접 노드 방문
        if (!vis[nxt]) {
            dfs(nxt);
        }
    }
}

// ✅ BFS 함수
void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << ' '; // 방문한 노드 출력

        for (int nxt : adj[cur]) {
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

    // ✅ 입력 받기
    cin >> n >> m >> start;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // ✅ 방문 순서를 보장하기 위해 정점 정렬
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    // ✅ DFS 실행
    dfs(start);
    cout << '\n';

    // ✅ BFS 실행 (방문 배열 초기화 후)
    fill(vis, vis + 1005, false); // 방문 배열 초기화
    bfs(start);
    cout << '\n';

    return 0;
}
