#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c) {
    if (n == 0) return 0; // 기저 조건: 가장 작은 1x1 크기
    int half = 1 << (n-1); // 배열 크기의 절반

    if (r < half && c < half) {
        // 1사분면
        return func(n-1, r, c);
    } else if (r < half && c >= half) {
        // 2사분면
        return (1 * half * half) + func(n-1, r, c-half);
    } else if (r >= half && c < half) {
        // 3사분면
        return (2 * half * half) + func(n-1, r-half, c);
    } else {
        // 4사분면
        return (3 * half * half) + func(n-1, r-half, c-half);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c) << '\n';
}
