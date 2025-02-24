#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = a[i]; // 자기 자신 포함하는 기본 값
    }
    
    int max_sum = 0; // 최대 합 초기화
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + a[i]); // 올바르게 갱신
            }
        }
        max_sum = max(max_sum, dp[i]); // 최댓값 갱신
    }
    
    cout << max_sum << '\n';
    return 0;
}
