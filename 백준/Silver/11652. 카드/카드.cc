#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    
    long long most_freq = arr[0]; // 최빈값 저장
    int max_count = 1, current_count = 1;
    
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1]) {
            current_count++;
        } else {
            current_count = 1;
        }
        
        if (current_count > max_count) {
            max_count = current_count;
            most_freq = arr[i]; // 최빈값 업데이트
        }
    }
    cout << most_freq << '\n';
    return 0;
}