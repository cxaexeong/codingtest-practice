#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void backtracking(int k, int start) {
    if (k==m) {
        for (int i = 0; i < m; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        return ;
    }
    
    for (int i = start; i <= n; i++) {
        arr[k] = i;
        backtracking(k+1, i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    backtracking(0,1);
    return 0;
}