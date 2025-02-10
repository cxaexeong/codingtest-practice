#include <bits/stdc++.h>
using namespace std;

unordered_set<string> s;  // 중복 없이 이름 저장

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; 
    cin >> n;  // 출입 기록 개수 입력
    
    while (n--) {
        string name, log;
        cin >> name >> log; // 이름과 로그 상태 입력
        if (log == "enter") s.insert(name);  // 입장 → 추가
        else s.erase(name);  // 퇴장 → 제거
    }

    // 정렬을 위해 unordered_set → vector 변환
    vector<string> ans(s.begin(), s.end());

    // 사전순 역순(내림차순) 정렬
    sort(ans.begin(), ans.end(), greater<string>());

    // 결과 출력
    for (auto x : ans) cout << x << '\n';
}
