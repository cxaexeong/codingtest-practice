#include <bits/stdc++.h>
using namespace std;

bool isprime(int x) {
    if (x == 1) return 0;
    if (x == 2) return 1;
    if (x % 2 == 0) return 0;
    
    for (int i = 3; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += isprime(x);
    }
    cout << ans << '\n';
    return 0;
}