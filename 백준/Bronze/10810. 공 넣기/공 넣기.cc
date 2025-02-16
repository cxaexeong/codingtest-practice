#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    
    vector<int> basket(n+1,0);
    
    for (int x = 0; x < m; x++) {
        int i,j,k;
        cin >> i >> j >> k;
        
        for (int xx = i; xx <= j; xx++) {
            basket[xx] = k;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << basket[i] << '\n';
    }
    cout << '\n';
    return 0;
}