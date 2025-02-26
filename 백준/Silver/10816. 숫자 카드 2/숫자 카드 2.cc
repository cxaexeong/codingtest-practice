#include <bits/stdc++.h>
using namespace std;

int n;
int a[500005];

int count_number(int target) {
    return upper_bound(a, a+n, target) - lower_bound(a, a+n, target);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    
    int m;
    cin >> m;
    
    while (m--) {
        int t;
        cin >> t;
        cout << count_number(t) << ' ';
    }
}