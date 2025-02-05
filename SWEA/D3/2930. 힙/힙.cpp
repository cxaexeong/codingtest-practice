#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        int n;
        cin >> n;

        priority_queue<int> pq;
        cout << "#" << t;

        while (n--) {
            int cmd;
            cin >> cmd;

            if (cmd == 1) {
                int x;
                cin >> x;
                pq.push(x);
            } else if (cmd == 2) {
                if (pq.empty()) cout << " -1";
                else {
                    cout << " " << pq.top();
                    pq.pop();
                }
            }
        }
        cout << "\n";
    }
    return 0;
}