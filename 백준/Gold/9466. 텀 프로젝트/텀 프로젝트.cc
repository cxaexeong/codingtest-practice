#include <bits/stdc++.h>
using namespace std;

int student[100005];
int n;
int state[100005];

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void dfs(int start) {
    int cur = start;
    while (true) {
        state[cur] = start;    // 현재 탐색 시작 노드를 기록
        cur = student[cur];    // 다음 노드로 이동 
        
        // 1. 이번 탐색에서 방문한 노드를 다시 만난 경우 (사이클 발견)
        if (state[cur] == start) {
            while (state[cur] != CYCLE_IN) {
                state[cur] = CYCLE_IN; // 사이클에 속하는 모든 노드를 CYCLE_IN으로 표시
                cur = student[cur];
            }
            return;
        }
        
        // 2. 이전 탐색에서 방문한 노드를 만난 경우 (사이클 외부 노드)
        else if (state[cur] != NOT_VISITED) return; // 탐색 종료
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        fill(state + 1, state + n + 1, NOT_VISITED);
        
        for (int i = 1; i <= n; i++)
            cin >> student[i];
        
        // 방문하지 않은 노드에서 탐색 시작
        for (int i = 1; i <= n; i++) {
            if (state[i] == NOT_VISITED) dfs(i);
        }
        
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            // 사이클에 포함되지 않은 학생 수 세기
            if (state[i] != CYCLE_IN) cnt++;
        }
        cout << cnt << '\n';
    }
}
