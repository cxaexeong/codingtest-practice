#include <bits/stdc++.h>
using namespace std;

int n;
string st;
vector<long long> arr;

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> st;
        reverse(st.begin(), st.end());
        arr.push_back(stoll(st));
    }
    sort(arr.begin(), arr.end());
    for (auto val : arr) cout << val << '\n';
    return 0;
}