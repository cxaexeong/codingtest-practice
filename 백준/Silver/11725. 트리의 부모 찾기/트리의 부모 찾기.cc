#include <bits/stdc++.h>
using namespace std;

int n;
int p[100001];
vector<int> adj[100001];

void dfs(int cur) {
    for (int nxt : adj[cur]) {
        if (p[cur] == nxt) continue;
        p[nxt] = cur;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    // 트리의 간선 개수 = n-1
    // 입력으로 n-1개의 간선을 받아야하므로..
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    // 루트 노드(1번) 은 출력할 필요없음
    for (int i = 2; i <= n; i++) cout << p[i] << '\n';
}