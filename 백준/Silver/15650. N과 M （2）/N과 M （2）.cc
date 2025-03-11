#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
bool isused[10];

void backtracking(int idx, int start) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    else {
        for (int i = start + 1; i <= n; i++) { // 이전 수보다 큰 수만 선택하기 위함 (오름차순)
            arr[idx] = i;
            backtracking(idx + 1, i);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    backtracking(0, 0);

}