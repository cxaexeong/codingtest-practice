#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> arr;

bool cmp(const string& a, const string& b) {
    int suma = 0, sumb = 0;
    
    if (a.size() != b.size()) return a.size() < b.size(); // 1. 길이비교
    
    // 2. 숫자 합 계산
    for (char c : a) if (isdigit(c)) suma += (c - '0');
    for (char c : b) if (isdigit(c)) sumb += (c - '0');
    if (suma != sumb) return suma < sumb;
    return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    arr.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end(), cmp);
    
    for (const string& a : arr) {
        cout << a << '\n';
    }
    return 0; 
}