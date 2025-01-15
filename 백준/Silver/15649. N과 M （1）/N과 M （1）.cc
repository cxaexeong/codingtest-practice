#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void backtracking(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) 
            cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
        cout << '\n';
        return; // 값을 반환하지 않고 단순히 함수 종료
    }
    
    for (int i = 1; i <= n; i++) { // 1부터 시작해야 함
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = true;
            backtracking(k+1);
            isused[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    backtracking(0);
}
