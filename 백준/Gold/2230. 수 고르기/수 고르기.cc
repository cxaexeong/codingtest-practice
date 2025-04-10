#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100005];
int mn = INT_MAX;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int en = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && a[en] - a[st] < m) en++;
        if (en >= n) break;    // en 범위 벗어날 경우 방지
        mn = min(mn, a[en] - a[st]);
    }
    cout << mn;
}