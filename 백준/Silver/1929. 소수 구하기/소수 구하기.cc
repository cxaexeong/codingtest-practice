#include <bits/stdc++.h>
using namespace std;

vector<bool> is_prime(1000001, true);

void sieve(int n) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            } 
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m,n;
    cin >> m >> n;
    
    sieve(n); // N까지 소수 판별
    
    for (int i = m; i <= n ; i++) {
        if (is_prime[i]) cout << i << '\n';
    }
}