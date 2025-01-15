#include <bits/stdc++.h>
using namespace std;

int n, s;        // 수열의 크기와 목표 합
int arr[20];     // 수열 저장
int result = 0;  // 합이 s가 되는 부분수열의 개수

void backtracking(int idx, int sum) {
    // 마지막 인덱스까지 탐색한 경우
    if (idx == n) {
        if (sum == s) result++;
        return;
    }
    
    // 현재 인덱스를 포함하는 경우
    backtracking(idx + 1, sum + arr[idx]);
    // 현재 인덱스를 포함하지 않는 경우
    backtracking(idx + 1, sum);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    backtracking(0,0);
    
    // 공집합인 경우를 제외해야 하므로 s가 0일 때는 1을 빼줌
    if (s==0) result--;
    
    cout << result;
    return 0;
}