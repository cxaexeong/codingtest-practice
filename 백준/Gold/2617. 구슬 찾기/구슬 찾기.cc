#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> heavier, lighter; // 그래프 저장
vector<bool> visited;

int bfs(int start, const vector<vector<int>> &graph) {
    queue<int> q;
    visited.assign(n+1, false);
    q.push(start);
    visited[start] = true;

    int cnt = 0; // 도달 가능한 노드 개수

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    heavier.resize(n+1);
    lighter.resize(n+1);

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        heavier[a].push_back(b); // a가 b보다 무거움
        lighter[b].push_back(a); // b가 a보다 가벼움
    }

    int mid = (n+1) / 2; // 중앙값 기준
    int ans = 0;         // 순위를 확정할 수 있는 구슬 개수

    // 각 구슬에 대해 bfs 실행
    for (int i = 1; i <= n; i++) {
        int heavy_cnt = bfs(i, heavier); // i보다 무거운 구슬 개수
        int light_cnt = bfs(i, lighter); // i보다 가벼운 구슬 개수

        // (무거운 개수 + 가벼운 개수) >= mid 조건 만족 시 개수 증가
        if (heavy_cnt >= mid || light_cnt >= mid) {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
} 