#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[51]; // 회원 번호는 1번부터 시작

// bfs로 최단 거리 계산
int bfs(int start) {
    vector<int> dist(n+1, -1);
    queue<int> q;
    
    dist[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int nxt : graph[cur]) {
            if (dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
    
    // 최장거리(Friend Score) 반환
    int maxDist = 0;
    for (int i = 1; i <= n; i++) {
        maxDist = max(maxDist, dist[i]);
    }
    return maxDist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int a,b;
    while (true) {
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<int> scores(n+1);
    int minScore = INT_MAX;
    
    for (int i = 1; i <= n; i++) {
        scores[i] = bfs(i);
        minScore = min(minScore, scores[i]);
    }
    
    vector<int> candidates;
    for (int i = 1; i <= n; i++) {
        if (scores[i] == minScore) 
            candidates.push_back(i);
    }
    
    cout << minScore << " " << candidates.size() << "\n";
    for (int c : candidates) {
        cout << c << "\n";
    }
    cout << "\n";
    return 0;
}

/*
각 회원(노드)에서 BFS 탐색을 수행하여 모든 다른 회원까지의 최단 거리를 구한다.
그 최단 거리들 중 최댓값을 해당 회원의 Friend Score로 설정한다.
Friend Score가 최소인 회원을 회장 후보로 선정.
*/