#include <bits/stdc++.h>
using namespace std;

int n,a,b;
pair<int, int> p[100004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    
   sort(p, p+n);
    
    
    for (int i = 0; i < n; i++) 
        cout << p[i].first << ' ' << p[i].second << '\n';
}