#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pow(ll a, ll b, ll m) {
    if (b==1) return a % m;        // base condition
    ll var = pow(a, b/2, m);
    var = var * var % m;           // b를 절반으로 나눈 값을 재귀적으로 계산 후, 제곱하여 결과를 val에 저장
    if (b % 2 == 0) return var;    // b가 짝수면 val을 반환    
    return var * a % m;            // b가 홀수면 val에 추가적으로 a를 곱한 값을 반환
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, b, c);
}