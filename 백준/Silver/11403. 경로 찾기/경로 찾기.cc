#include <bits/stdc++.h>
using namespace std;

int n;
int graph[100][100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    for (int k = 0; k < n; k++) {    // 1. 중간 노드 k 설정
        for (int i = 0; i < n; i++) {    // 2. 시작 노드i
            for (int j = 0; j < n; j++) {    // 3. 도착 노드 j
                if (graph[i][k] && graph[k][j]) {    // k를 거쳐갈 수 있다면
                    graph[i][j] = 1;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;     
}