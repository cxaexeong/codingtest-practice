#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<int> q;
    
    int n;
    cin >> n;
    
    for (int i = 1; i < n+1; i++) {
        q.push(i);
    }
    
    while (q.size() > 1) {
        q.pop();            // 맨 위 숫자를 버림
        q.push(q.front());  // 그 다음 숫자를 맨 뒤로 옮김
        q.pop();            // 원래 두번째였던 숫자를 큐에서 제거
    }
    cout << q.front() << endl;    
}