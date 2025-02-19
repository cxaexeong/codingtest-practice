#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // 정렬 기준: (1) 길이 짧은 순 (2) 길이가 같으면 사전순
    sort(arr.begin(), arr.end(), [](const string& u, const string& v){
        int ul = u.length();
        int vl = v.length();
        
        if (ul != vl) return ul < vl; // 길이 짧은 순
        return u < v; // 길이가 같으면 사전순
    });

    // 중복 제거
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    // 출력
    for (const string& s : arr) {
        cout << s << '\n';
    }

    return 0;
}
