#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int,int>> lines(n);
    
    for (int i = 0; i < n; i++) {
        cin >> lines[i].first >> lines[i].second;
    }
    
    // 시작점 기준으로 정렬
    sort(lines.begin(), lines.end());
    
    ll total_length = 0;
    int start = lines[0].first;
    int end = lines[0].second;
    
    // 선분 합치기
    for (int i = 1; i < n; i++) {
        int x1 = lines[i].first, x2 = lines[i].second;
        
        if (x1 <= end) {                    // 겹치는 경우
            end = max(x2, end);   // 끝점 확장
        } else {                            // 겹치지 않는 경우
            total_length += end - start;
            start = x1;
            end = x2;
        }
    }
    total_length += (end - start);
    cout << total_length << '\n';
    return 0;
}