#include <bits/stdc++.h>
using namespace std;

int n,m;
unordered_map<string, int> name_to_num;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    vector<string> num_to_name(n+1);
    
    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        name_to_num[name] = i;
        num_to_name[i] = name;
    }
    while (m--) {
        string query;
        cin >> query;
        
        if (isdigit(query[0])) {
            cout << num_to_name[stoi(query)] << '\n';
        } else {
            cout << name_to_num[query] << '\n';
        }
    }
    return 0;
}