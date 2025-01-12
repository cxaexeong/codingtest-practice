#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

int board[102][102];
bool v[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n >> k;

    // 직사각형 입력 및 영역 표시
    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; i++) { // 주의: y축은 위에서 아래로
            for (int j = x1; j < x2; j++) { // x축은 왼쪽에서 오른쪽으로
                board[i][j] = 1;
            }
        }
    }
    
    int cnt = 0; // 영역 개수
    vector<int> ans; // 각 영역의 크기 저장
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1 || v[i][j]) continue; // 직사각형이거나 방문한 경우 스킵
            
            // 새로운 영역 탐색 시작
            queue<pair<int, int>> q;
            v[i][j] = 1;
            q.push({i, j});
            int width = 0; // 영역의 크기 계산
            
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                width++;
                
                for (int d = 0; d < 4; d++) {
                    int nx = cur.x + dx[d];
                    int ny = cur.y + dy[d];
                    
                    // 유효 범위 체크 및 조건 확인
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] == 1 || v[nx][ny]) continue;
                    
                    q.push({nx, ny});
                    v[nx][ny] = 1;
                }
            }
            ans.push_back(width);
            cnt++; // 새로운 영역 발견
        }
    }
    
    // 결과 출력
    sort(ans.begin(), ans.end());
    cout << cnt << '\n';
    for (int i : ans) 
        cout << i << ' ';
    
    return 0;
}
