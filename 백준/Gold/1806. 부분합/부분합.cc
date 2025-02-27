#include <bits/stdc++.h>
using namespace std;

int n,s;
vector<int> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int sum = 0, st = 0, en = 0;
    int min_len = INT_MAX;
    
    while (en < n) {
        sum += arr[en];
        while (sum >= s) {
            min_len = min(min_len, en - st + 1);
            sum -= arr[st];
            st++;
        }
        en++;
    }
    cout << (min_len == INT_MAX ? 0 : min_len);
}