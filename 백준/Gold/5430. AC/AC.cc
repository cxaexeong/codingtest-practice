#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        string p;
        cin >> p;
        
        int n;
        cin >> n;
        
        string arr;
        cin >> arr;
        
        // deque에 배열 입력
        deque<int> dq;
        string num;     // 임시 저장
        for (char c : arr) {
            if (isdigit(c)) {
                num += c;
            } else if (!num.empty()) {
                dq.push_back(stoi(num));
                num.clear();
            }
        }
        
        // 명령어 처리
        bool reversed = false;
        bool error = false;
        
        for (char cmd : p) {
            if (cmd == 'R') {
                reversed = !reversed;
            } else if (cmd == 'D') {
                if (dq.empty()) {
                    cout << "error\n";
                    error = true;
                    break;
                }
                if (reversed) {
                    dq.pop_back();
                } else {
                    dq.pop_front();
                }
            }
        } 
        // 결과 출력
        if (!error) {
            cout << "[";
            while (!dq.empty()) {
                if (reversed) {
                    cout << dq.back();
                    dq.pop_back();
                } else {
                    cout << dq.front();
                    dq.pop_front();
                }
                if (!dq.empty()) cout << ",";
            }
            cout << "]\n";
        }
    }
    return 0;
}