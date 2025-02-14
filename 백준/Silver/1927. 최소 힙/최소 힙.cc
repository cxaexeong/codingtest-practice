#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int>> pq; // unsigned int 유지
    
    for (int i = 0; i < n; i++) {
        unsigned int t;
        cin >> t;
        
        if (t) pq.push(t);  // 입력값 `t`를 저장
        else {
            if (pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << '\n'; // 최소값 출력
                pq.pop();
            }
        }
    }
}
