#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m; // 입력 먼저 받기

    vector<int> basket(n + 1);
    
    // 바구니 초기화 (1~N 번호 넣기)
    for (int i = 1; i <= n; i++) 
        basket[i] = i;

    // 구간 뒤집기
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        reverse(basket.begin() + a, basket.begin() + b + 1); // 구간 뒤집기
    }

    // 결과 출력
    for (int i = 1; i <= n; i++)
        cout << basket[i] << " ";

    return 0;
}
