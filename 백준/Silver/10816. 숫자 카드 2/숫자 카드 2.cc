#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    arr.resize(n);
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;
        cout << upper_bound(arr.begin(), arr.end(), target) 
            - lower_bound(arr.begin(), arr.end(), target) << ' ';
    }
    return 0;
}