#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);    // 벡터 크기 미리 할당(메모리 최적화)
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.rbegin(), arr.rend());
    
    stringstream ss;
    for (const int &num : arr) {
        ss << num << '\n';
    }
    
    cout << ss.str();    // stringstream에 저장된 모든 문자열을 하나의 string으로 변환
    return 0;
}

// cout을 반복 호출하여 느림	stringstream 사용 후 cout << ss.str(); 한 번에 출력