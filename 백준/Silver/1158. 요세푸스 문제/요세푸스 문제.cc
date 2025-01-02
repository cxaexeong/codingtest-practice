#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    list<int> L;
    for (int i = 1; i <= n; ++i) {
        L.push_back(i);
    }

    auto it = L.begin();
    vector<int> result;

    while (!L.empty()) {
        for (int i = 0; i < k - 1; ++i) {
            ++it;
            if (it == L.end()) it = L.begin();
        }
        result.push_back(*it);
        it = L.erase(it);
        if (it == L.end()) it = L.begin();
    }

    cout << '<';
    for (size_t i = 0; i < result.size(); ++i) {
        if (i != 0) cout << ", ";
        cout << result[i];
    }
    cout << '>';
    return 0;
}
