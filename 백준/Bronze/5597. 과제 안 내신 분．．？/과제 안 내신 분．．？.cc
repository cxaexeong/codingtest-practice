#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[31];
    fill(arr, arr + 31, -1);
    
    for (int i = 0; i < 28; i++) {
        int n;
        cin >> n;
        arr[n] = n;
    }
    for (int i = 1; i <= 30; i++) {
        if (arr[i] == -1) cout << i << '\n';
    }
    return 0;
}