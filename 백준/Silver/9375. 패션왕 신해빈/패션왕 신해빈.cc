#include <bits/stdc++.h>
using namespace std;

int t, n;
unordered_map<string, int> clothes;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n;
        clothes.clear();  // 새로운 테스트 케이스마다 초기화
        
        for (int i = 0; i < n; i++) {
            string name, type;
            cin >> name >> type;
            clothes[type]++;  // 같은 종류의 의상 개수 카운트
        }

        int result = 1;
        for (auto& [type, count] : clothes) {
            result *= (count + 1);  // (해당 종류의 개수 + 1) (안 입는 경우 포함)
        }

        cout << result - 1 << '\n';  // 아무것도 입지 않는 경우 제외
    }

    return 0;
}
