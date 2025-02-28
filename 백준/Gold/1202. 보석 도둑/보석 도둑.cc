#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n,k;
pair<int,int> jewel[300005]; // {가격, 무게}
multiset<int> bag;   // 자동 정렬, 이진 탐색, 중복 허용

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) 
        cin >> jewel[i].second >> jewel[i].first;
    sort(jewel, jewel + n);
    
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        bag.insert(c);
    }
    
    ll ans= 0;
    
    for (int i = n - 1; i >= 0; i--) {
        int m, v;
        tie(v, m) = jewel[i];
        
        auto it = bag.lower_bound(m);
        if (it == bag.end()) continue;
    
        ans += v;
        bag.erase(it);
    }
    
    cout << ans;
    return 0;
}