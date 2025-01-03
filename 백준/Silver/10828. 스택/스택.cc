#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    string command;

    while (n--) {
        cin >> command;

        if (command == "push") {
            int x;
            cin >> x;
            s.push(x);  // 세미콜론 추가
        } else if (command == "pop") {
            if (s.empty()) {
                cout << -1 << '\n';  // cout 오타 수정
            } else {
                cout << s.top() << '\n';
                s.pop();  // 세미콜론 추가
            }
        } else if (command == "size") {
            cout << s.size() << '\n';
        } else if (command == "empty") {
            cout << (s.empty() ? 1 : 0) << '\n';
        } else if (command == "top") {
            if (s.empty()) {
                cout << -1 << '\n';
            } else {
                cout << s.top() << '\n';
            }
        }
    }

    return 0;
}
