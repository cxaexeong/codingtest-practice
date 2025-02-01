// 백트래킹(DFS) 방식으로 연산자의 모든 조합을 시도
// 연산자 개수가 N-1개이므로, **완전 탐색(순열)**으로 충분히 해결 가능
// 연산 결과의 최대값과 최소값을 갱신
#include <bits/stdc++.h>
using namespace std;

int n;
int nums[11];          // 최대 11개의 숫자 저장
int ops[4];            // 연산자 개수 (+, -, *, /)
int maxResult = INT_MIN;
int minResult = INT_MAX;

// 백트래킹을 이용한 dfs
void dfs (int idx, int result) {
    if (idx == n) {    // 모든 숫자를 사용했을 때
        maxResult = max(maxResult, result);
        minResult = min(minResult, result);
        result;
    }
    
    for (int i = 0; i < 4; i++) {
        if (ops[i] > 0) {  // 해당 연산자가 남아있다면
            ops[i]--;      // 연산자 사용
            
            if (i == 0) dfs(idx + 1, result + nums[idx]);        // 덧셈
            else if (i == 1) dfs(idx + 1, result - nums[idx]);   // 뺄셈
            else if (i == 2) dfs(idx + 1, result * nums[idx]);   // 곱셈
            else if (i == 3) dfs(idx + 1, result / nums[idx]);   // 나눗셈 
            
            ops[i]++;    // 백트래킹 (연산자 개수 복구)
        } 
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < 4; i++) cin >> ops[i];
    
    dfs(1, nums[0]);
    
    cout << maxResult << '\n' << minResult << '\n';
}