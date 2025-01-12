#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
string board[30];
//int dist[30];
bool v[30][30];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

int bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});
    v[x][y] = true; 
    //dist[x][y] = 1; 
    
    //int count = 0;
    int count = 1; // 현재 단지의 크기 초기화
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        //cnt++;
        
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] == '0' || v[nx][ny]) continue;
            
            //dist[nx][ny] = dist[cur.x][cur.y] + 1;
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
    
    //int complex = 0; 각 단지의 크기를 complex로 단일 변수로 다룰 수 없으므로, 벡터를 사용해야 함.
    vector<int> complexes; // 단지 크기 저장
    for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if (board[i][j] == '1' && !v[i][j])
                complexes.push_back(bfs(i,j)); // 새로운 단지 발견 시 bfs 수행
        }
        
    sort(complexes.begin(), complexes.end());  // 단지 크기 정렬
    cout << complexes.size() << '\n';           // 총 단지 수 출력
    for (int size : complexes) 
        cout << size << '\n';                  // 각 단지 크기 출력
    
    return 0;  
}