#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
bool isused[10];

void backtracking(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = true;
            backtracking(k+1);
            isused[i] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    backtracking(0);
}