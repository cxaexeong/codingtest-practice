#include <bits/stdc++.h>
using namespace std;

int dp[41][2];  // 0과 1이 호출된 횟수를 저장하는 DP 배열

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n;
    cin >> t;

    // 초기값 설정
    dp[0][0] = 1; dp[0][1] = 0;  // fibonacci(0): 0 한 번, 1은 0번
    dp[1][0] = 0; dp[1][1] = 1;  // fibonacci(1): 1 한 번, 0은 0번

    // DP 배열 채우기 (2부터 40까지)
    for (int i = 2; i <= 40; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-2][0];  // 0 호출 횟수
        dp[i][1] = dp[i-1][1] + dp[i-2][1];  // 1 호출 횟수
    }

    while (t--) {
        cin >> n;
        cout << dp[n][0] << ' ' << dp[n][1] << '\n';
    }

    return 0;
}
