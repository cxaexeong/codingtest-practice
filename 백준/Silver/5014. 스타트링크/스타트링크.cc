#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

int main() {
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    
    vector<bool> v(F+1, false);    // 총 방문 여부 체크
    queue<pair<int,int>> q;        // {현재 층, 클릭 횟수}
    
    // 시작 위치
    q.push({S,0});
    v[S] = true;
    
    while (!q.empty()) {
        int current = q.front().x;
        int clicks = q.front().y;
        q.pop();
        
        // 목표 층에 도달한 경우
        if (current == G) {
            cout << clicks << endl;
            return 0;
        }
        
        // 위로 이동
        int up = current + U;
        if (up <= F && !v[up]) {
            v[up] = true;
            q.push({up, clicks + 1});
        }
        
        // 아래로 이동
        int down = current - D;
        if (down >= 1 && !v[down]) {
            v[down] = true;
            q.push({down, clicks + 1});
        }
    }
    
    // 목표 층에 도달하지 못한 경우
    cout << "use the stairs" << endl;
    return 0;
}