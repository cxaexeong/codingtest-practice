#include <bits/stdc++.h>
using namespace std;
int n;
int p[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    
    sort(p, p+n);
    
    int ans = 0;
    int sum = 0; // 누적 시간
    
    for (int i = 0; i < n; i++) {
        sum += p[i];
        ans += sum;
    }
    cout << ans;
    return 0;
}