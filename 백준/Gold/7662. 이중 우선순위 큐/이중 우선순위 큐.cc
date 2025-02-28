#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int k;
        cin >> k;
        
        multiset<int> ms;
        
        for (int i = 0; i < k; i++) {
            char op;
            int num;
            cin >> op >> num;
            
            if (op == 'I') {
                ms.insert(num);
            } else if (!ms.empty()) {
                if (num == 1) {
                    // ms.end는 마지막 원소의 한 칸 뒤를 가리킴
                    ms.erase(prev(ms.end()));  // 최대값 삭제
                } else {
                    ms.erase(ms.begin());  // 최소값 삭제
                }
            }
        }

        if (ms.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << *ms.rbegin() << " " << *ms.begin() << "\n";
        }
    }

    return 0;
}
