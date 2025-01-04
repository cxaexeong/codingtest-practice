#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    stack<int> s;
    vector<string> operations;
    vector<int> sequence(n);
    
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    
    int current = 1;
    
    for (int i = 0; i < n; i++) {
        int target = sequence[i];
        
        while (current <= target) {
            s.push(current++);
            operations.push_back("+");
        }
        
        if (s.top() == target) {
            s.pop();
            operations.push_back("-");
        } else {
            cout << "NO" << '\n';
            return 0;
        }   
    }
    for (const string& op : operations) {
        cout << op << '\n';
    }
    return 0;
}