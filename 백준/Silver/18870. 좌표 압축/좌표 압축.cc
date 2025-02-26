#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
unordered_map<int, int> compressed;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    arr.resize(n);
    
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> sorted_arr = arr; // 원본 유지
    sort(sorted_arr.begin(), sorted_arr.end());
    
    sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());
    
    for (int i = 0; i < sorted_arr.size(); i++) {
        compressed[sorted_arr[i]] = i;
    }    

    for (int i = 0; i < n; i++) {
        cout << compressed[arr[i]] << ' ';
    }
    return 0;
}
