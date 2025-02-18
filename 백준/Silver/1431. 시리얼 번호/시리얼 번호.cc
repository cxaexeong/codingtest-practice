#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> arr; // 크기 지정 없이 선언

// 비교 함수 (커스텀 정렬)
bool cmd(const string& a, const string& b) {
    int suma = 0, sumb = 0;
    
    if (a.size() != b.size()) return a.size() < b.size(); // 1. 길이 비교
    
    // 2. 숫자 합 계산
    for (char c : a) if (isdigit(c)) suma += (c - '0');
    for (char c : b) if (isdigit(c)) sumb += (c - '0');
    
    if (suma != sumb) return suma < sumb; // 2. 숫자 합 비교
    return a < b; // 3. 사전순 비교
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> n;
    arr.resize(n); // 크기 설정

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end(), cmd); // 전체 정렬
    
    for (const string& a : arr) {
        cout << a << '\n';
    }
    return 0;
}
