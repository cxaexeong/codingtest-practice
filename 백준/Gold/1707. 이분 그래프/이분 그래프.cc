#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int RED = 1;
const int BLUE = -1;

vector<int> graph[20001];  // 인접 리스트
int color[20001];          // 색 정보 저장

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    color[start] = RED; // 시작 노드를 RED로 색칠

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int next : graph[node]) {
            if (color[next] == 0) { // 아직 색칠되지 않은 경우
                color[next] = -color[node]; // 반대 색으로 칠함
                q.push(next);
            } else if (color[next] == color[node]) {
                return false; // 인접한 두 노드가 같은 색이면 이분 그래프가 아님
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int K;
    cin >> K;

    while (K--) {
        int V, E;
        cin >> V >> E;

        // 그래프 초기화
        for (int i = 1; i <= V; i++) {
            graph[i].clear();
            color[i] = 0;
        }

        // 간선 입력
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // 모든 정점에 대해 이분 그래프 판별
        bool isBipartite = true;
        for (int i = 1; i <= V; i++) {
            if (color[i] == 0) { // 방문하지 않은 경우만 bfs 실행
                if (!bfs(i)) {
                    isBipartite = false;
                    break;
                }
            }
        }

        cout << (isBipartite ? "YES" : "NO") << '\n';
    }

    return 0;
}
