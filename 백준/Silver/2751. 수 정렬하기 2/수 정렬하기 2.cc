#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> arr;
    arr.reserve(n);    // 벡터의 크기를 미리 예약하여 push_back 속도 향상
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    sort(arr.begin(), arr.end());
    
    for (const int &num : arr) {
        cout << num << '\n';
    }
    return 0;
}