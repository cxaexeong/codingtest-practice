#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<int> basket(n + 1);
    iota(basket.begin(), basket.end(), 0); // 바구니 번호 초기화

    while (m--) {
        int a, b;
        cin >> a >> b;
        swap(basket[a], basket[b]); // swap 함수 사용
    }

    for (int i = 1; i <= n; i++)
        cout << basket[i] << " ";
    
    return 0;
}
