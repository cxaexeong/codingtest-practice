#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;                // 스택 선언
    vector<string> operations;   // 연산 기록
    vector<int> sequence(n);     // 목표 수열

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];      // 수열 입력
    }

    int current = 1;             // 스택에 넣을 숫자 (1부터 시작)

    for (int i = 0; i < n; i++) {
        int target = sequence[i];

        // 목표 숫자에 도달할 때까지 push
        while (current <= target) {
            s.push(current++);
            operations.push_back("+");
        }

        // 스택의 최상단이 목표 숫자와 같으면 pop
        if (s.top() == target) {
            s.pop();
            operations.push_back("-");
        } else {
            // 스택에서 목표 숫자를 만들 수 없으면 "NO" 출력 후 종료
            cout << "NO" << endl;
            return 0;  // 프로그램 종료
        }
    }

    // 연산 출력
    for (const string& op : operations) {
        cout << op << '\n';
    }

    return 0;
}
