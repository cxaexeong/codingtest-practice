#include <bits/stdc++.h>
using namespace std;

int tri[502][502];
int dp[502][502];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {  // 🚀 `j <= i`로 수정 (i < n은 잘못된 조건)
            cin >> tri[i][j];
        }
    }
    
    dp[0][0] = tri[0][0]; // 시작점 초기화
    
    // DP 테이블 채우기
    for (int i = 1; i < n; i++) {  // 🚀 `i <= n` → `i < n`으로 수정
        for (int j = 0; j <= i; j++) {  // 🚀 `j <= i`로 수정
            if (j == 0) {    
                dp[i][j] = dp[i-1][j] + tri[i][j];  // 왼쪽 끝 (위쪽에서만 올 수 있음)
            } else if (j == i) {    
                dp[i][j] = dp[i-1][j-1] + tri[i][j];  // 오른쪽 끝 (대각선 위에서만 올 수 있음)
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + tri[i][j]; // 최댓값 갱신
            }
        }
    }

    // 🚀 마지막 줄에서 최대값 찾기
    cout << *max_element(dp[n-1], dp[n-1] + n) << '\n';

    return 0;
}
