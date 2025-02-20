#include <bits/stdc++.h>
using namespace std;

int d[1005][3];
int r[1005], g[1005], b[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) 
        cin >> r[i] >> g[i] >> b[i];
    
    // 초기값 설정
    d[1][0] = r[1];
    d[1][1] = g[1];
    d[1][2] = b[1];

    // 점화식 적용 (이전 최솟값 + 현재 색깔 비용)
    for (int i = 2; i <= n; i++) {
        d[i][0] = min(d[i-1][1], d[i-1][2]) + r[i];  // 현재 집을 빨강으로 칠할 경우
        d[i][1] = min(d[i-1][0], d[i-1][2]) + g[i];  // 현재 집을 초록으로 칠할 경우
        d[i][2] = min(d[i-1][0], d[i-1][1]) + b[i];  // 현재 집을 파랑으로 칠할 경우
    }

    // 마지막 집까지 칠했을 때 최소 비용 출력
    cout << min({d[n][0], d[n][1], d[n][2]});
}
