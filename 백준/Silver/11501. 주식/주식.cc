#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        int n;
        cin >> n;
        vector<int> stock(n);
        
        for (int i = 0; i < n; i++) {
            cin >> stock[i];
        }

        ll max_profit = 0;
        int max_price = 0;

        // 뒤에서부터 순회
        for (int i = n - 1; i >= 0; i--) {
            if (stock[i] > max_price) {
                max_price = stock[i]; // 최고가 갱신
            } else {
                max_profit += (max_price - stock[i]); // 이익 계산
            }
        }

        cout << max_profit << '\n';
    }
}
