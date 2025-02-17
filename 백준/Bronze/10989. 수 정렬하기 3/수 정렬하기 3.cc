#include <bits/stdc++.h>
using namespace std;

int countArr[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        countArr[x]++;    // 입력값을 인덱스로 사용하여 개수 증가
    }
    
    for (int i = 1; i<= 10000; i++) {
        while (countArr[i]--) {
            cout << i << '\n';
        }
    }
    return 0;
}

// vector<int> + sort() 사용 (기존 코드) 시
// 40Mb 이상 (메모리 초과), O(n log n), 정렬과정에서 메모리 초과 발생

/// 계수 정렬 이용시 -> 약 40KB (10001 × 4B)
// O(n + k) ≈ O(n), 정렬 없이 빠른 처리 가능