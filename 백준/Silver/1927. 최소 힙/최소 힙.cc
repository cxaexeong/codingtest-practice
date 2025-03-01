#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > 0) {
            pq.push(x);
        } else if (x == 0) {
            if (pq.empty()) cout << "0\n";  // 🛠 비어있으면 0 출력
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}
