#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
pair<int, int> jewel[300005]; // {가격, 무게}
multiset<int> bag;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    
    // 보석 입력 (무게, 가격 순서) → {가격, 무게}로 저장
    for (int i = 0; i < n; i++) 
        cin >> jewel[i].second >> jewel[i].first;
    
    // 보석을 가격 기준 오름차순 정렬
    sort(jewel, jewel + n);
    
    // 🚨 가방 개수만큼 입력받아야 함
    for (int i = 0; i < k; i++) {  
        int c;
        cin >> c;
        bag.insert(c);
    }
    
    ll ans = 0;

    // 가격이 높은 보석부터 순회
    for (int i = n - 1; i >= 0; i--) {
        int m, v;
        tie(v, m) = jewel[i]; // 가격 v, 무게 m
        
        // 현재 보석을 넣을 수 있는 가장 작은 가방 찾기
        auto it = bag.lower_bound(m);
        if (it == bag.end()) continue;  // 가방이 없다면 건너뜀

        ans += v;  // 보석 가격 추가
        bag.erase(it);  // 사용한 가방 제거
    }
    
    cout << ans;
    return 0;
}
