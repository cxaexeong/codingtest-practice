#include <bits/stdc++.h>
using namespace std;

int k, l;
unordered_map<string, int> last_seen;
vector<string> id;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> l;
    id.resize(l);
    
    for (int i = 0; i < l; i++) {
        cin >> id[i];
        last_seen[id[i]] = i; // 마지막으로 등장한 위치 저장
    }

    unordered_set<string> printed;
    int count = 0;

    for (int i = 0; i < l; i++) {
        if (last_seen[id[i]] == i && printed.find(id[i]) == printed.end()) {
            cout << id[i] << '\n';
            printed.insert(id[i]);
            count++;
            if (count == k) break;
        }
    }
}
