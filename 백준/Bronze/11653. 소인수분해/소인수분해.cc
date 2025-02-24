#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    for (int i = 2; i * i <= n; i++) { // 2부터 sqrt(n)까지 반복
        while (n % i == 0) { // i로 나누어 떨어지는 동안
            cout << i << '\n'; 
            n /= i; // N을 i로 나눔
        }
    }
    
    if (n > 1) cout << n << '\n'; // 마지막에 남은 소수 출력
    
    return 0;
}
