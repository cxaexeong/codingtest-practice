#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
//bool isused[10]; 이 문제에서는 중복 불가이기 때문에 중복체크배열 제거

void backtracking(int k, int start) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i = start; i <= n; i++) { // start 이상의 숫자만 탐색하기 때문에 오름차순 보장
            arr[k] = i;                // 현재 숫자를 선택
            backtracking(k+1, i+1);    // 다음 숫자 탐색 (i+1부터 시작) -> 같은 숫자 탐색x
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    backtracking(0, 1);    // 1부터 탐색 시작
    return 0;
}