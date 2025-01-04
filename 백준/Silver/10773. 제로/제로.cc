#include <bits/stdc++.h>
using namespace std;

int k;
stack<int> s;
int ans = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k;
    
    while (k--) {
        int n;
        cin >> n;
        
        if (n == 0) s.pop();
        else s.push(n);
    }
    
    // 스택에 쌓여 있는 모든 값을 더해줌
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    cout << ans;
}