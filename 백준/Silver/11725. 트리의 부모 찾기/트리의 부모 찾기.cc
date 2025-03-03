#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> tree[100001];
int parent[100001];

void bfs() {
    queue<int> q;
    q.push(1);    // 루트 노드부터 시작
    parent[1] = 0;    // 루트의 부모는 없음 (0으로 처리)
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int nxt : tree[cur]) {
            if (parent[nxt] == 0) {    // 아직 부모가 결정되지 않은 경우
                parent[nxt] = cur;
                q.push(nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    bfs();
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }
    return 0;
}