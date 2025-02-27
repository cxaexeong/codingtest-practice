#include <bits/stdc++.h>
using namespace std;

int n,m;
unordered_map<string, string> do_2_pw;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        string domain, pw;
        cin >> domain >> pw;
        do_2_pw[domain] = pw;
    }
    
    while (m--) {
        string query;
        cin >> query;
        cout << do_2_pw[query] << '\n';
    }
    return 0;  
}