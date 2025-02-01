#include <bits/stdc++.h>
using namespace std;

int n;
int nums[11];
int ops[4];
int maxResult = INT_MIN;
int minResult = INT_MAX;

void dfs(int idx, int result) {
    if (idx == n) {
        maxResult = max(maxResult, result);
        minResult = min(minResult, result);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (ops[i] > 0) {
            ops[i]--;
            
            if (i==0) dfs(idx+1, result + nums[idx]);
            else if (i==1) dfs(idx+1, result - nums[idx]);
            else if (i==2) dfs(idx+1, result * nums[idx]);
            else if (i==3) dfs(idx+1, result / nums[idx]);
            
            ops[i]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = 0; i < 4; i++)
        cin >> ops[i];
    
    dfs(1, nums[0]);
    cout << maxResult << '\n' << minResult << '\n';
}