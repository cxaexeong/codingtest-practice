#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
string board[30];
bool v[30][30];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

int bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});
    v[x][y] = true;
    
    int count = 1;
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] == '0' || v[nx][ny]) continue;
            
            q.push({nx, ny});
            v[nx][ny] = true;
            count++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> board[i];
    
    vector<int> complex;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '1' && !v[i][j]) 
                complex.push_back(bfs(i,j));
        }
    sort(complex.begin(), complex.end());
    cout << complex.size() << '\n';
    for (int size : complex) {
        cout << size << '\n';
    }
    return 0;
}