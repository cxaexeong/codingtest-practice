#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    stack<int> s;
    vector<string> operations;
    vector<int> sequence(n);
    
    // 수열 입력
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    
    int current = 1;  // 스택에 넣을 숫자 (1부터 시작)
    
    for (int i = 0; i < n; i++) {
        int target = sequence[i];
        
        // 목표 숫자에 도달할 때까지 push
        while (current <= target) {
            s.push(current++);
            operations.push_back("+");
        }
        
        // 스택 최상단이 target과 같을 때 pop
        if (s.top() == target) {
            s.pop();
            operations.push_back("-");
        } else {
            cout << "NO" << '\n';
            return 0;
        }
    }
    
    // 연산 출력
    for (const string& op : operations) {
        cout << op << '\n';
    }
    
    return 0;
}
