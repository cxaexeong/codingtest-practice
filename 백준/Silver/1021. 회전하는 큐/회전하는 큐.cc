#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,k;
    cin >> n >> k;
    
    deque<int> dq;
    vector<int> targets(k);
    
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    
    for (int i = 0; i < k; i++) {
        cin >> targets[i];
    }
    
    int totalRotations = 0;
    
    for (int target : targets) {
        int idx = find(dq.begin(), dq.end(), target) - dq.begin();
        
        int leftRotations = idx;
        int rightRotations = dq.size() - idx;
        
        totalRotations += min(leftRotations, rightRotations);
        
        if (leftRotations <= rightRotations) {
            while (leftRotations--) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            while (rightRotations--) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        
        dq.pop_front();
    }
    cout << totalRotations << endl;
    return 0;    
}
