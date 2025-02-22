#include <bits/stdc++.h>
using namespace std;

int n;
int weight[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    
    sort(weight, weight + n);
    
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int cur_w = weight[i] * (n - i);
        mx = max(mx, cur_w);
    }
    cout << mx << '\n';
    return 0;
}