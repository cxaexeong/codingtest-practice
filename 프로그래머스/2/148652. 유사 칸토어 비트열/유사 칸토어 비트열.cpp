#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int countOnes(int n, ll l, ll r, ll length) {
    if (n == 0) return 1;   // n = 0이면 항상 "1"
    
    ll unit = length / 5;   // 현재 단계에서 하나의 블록 크기
    int cnt = 0;
    
    // 5개 블록을 확인
    for (int i = 0; i < 5; i++) {
        ll start = i * unit + 1;    // 현재 블록 시작 인덱스
        ll end = start + unit - 1;  // 현재 블록 끝 인덱스
        
        if (i == 2) continue;       // 가운데 "00000" 블록은 스킵
        
        // 현재 블록이 [l, r]과 겹치는 경우만 탐색
        if (r >= start && l <= end) {
            cnt += countOnes(n - 1, max(l, start) - start + 1, min(r, end) - start + 1, unit);
        }
    }
    return cnt;
}

int solution(int n, long long l, long long r) {
    ll length = 1;
    for (int i = 0; i < n; i++) length *= 5;    // 전체 비트열 길이 5^n
    return countOnes(n, l, r, length);
}