#include <bits/stdc++.h>
using namespace std;

int kaing(int m, int n, int x, int y) {
    int lcm_mn = lcm(m,n);
    for (int k = x; k <= lcm_mn; k+= m) {
        if ((k-1) % n + 1 == y) return k;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        int m,n,x,y;
        cin >> m >> n >> x >> y;
        cout << kaing(m, n, x, y) << '\n';
    } 
    return 0;
}