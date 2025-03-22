#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(vector<vector<int>>& maps) {
    int n = maps.size();
    int m = maps[0].size();
    int mn = INT_MAX;
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    
    queue<pair<int,int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    dist[0][0] = 1;
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        
        for (int d = 0; d < 4; d++) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny] || maps[nx][ny] == 0) continue;
            
            q.push({nx, ny});
            visited[nx][ny] = true;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
    // 상대팀 진영 도착 불가하면 -1
    if (dist[n-1][m-1] == 0) return -1;
    return dist[n-1][m-1];
}

int solution(vector<vector<int>> maps)
{    
    return bfs(maps);
}