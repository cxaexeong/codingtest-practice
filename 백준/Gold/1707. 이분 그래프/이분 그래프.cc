#include <bits/stdc++.h>
using namespace std;

const int red = 1;
const int blue = -1;

vector<int> graph[20005];
int color[20005];

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    color[start] = red;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int nxt : graph[cur]) {
            if (color[nxt] == 0) {
                color[nxt] = -color[cur];
                q.push(nxt);
            } else if (color[nxt] == color[cur]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k;
    cin >> k;
    
    while (k--) {
        int v,e;
        cin >> v >> e;
        
        for (int i = 1; i <= v; i++) {
            graph[i].clear();
            color[i] = 0;
        }
        
        for (int i = 0; i < e; i++) {
            int u,v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        bool isBi = true;
        for (int i = 1; i <= v; i++) {
            if (color[i] == 0) {
                if (!bfs(i)) {
                    isBi = false;
                    break;
                }
            }
        }
        cout << (isBi? "YES" : "NO") << '\n';
    }
    return 0;
}