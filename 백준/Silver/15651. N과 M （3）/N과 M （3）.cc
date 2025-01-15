#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void backtracking(int k) {
    if (k == m) { // M개의 숫자를 모두 선택한 경우 출력
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) { // 1부터 N까지 탐색
        arr[k] = i;                // 현재 숫자를 선택
        backtracking(k + 1);       // 다음 위치 선택
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;       // N과 M 입력
    backtracking(0);     // 탐색 시작
    return 0;
}
