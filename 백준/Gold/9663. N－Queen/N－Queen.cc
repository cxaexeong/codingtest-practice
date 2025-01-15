#include <bits/stdc++.h>
using namespace std;

int n;             // 체스판 크기
int result = 0;    // 가능한 경우의 수
bool isused1[40];  // 열 체크
bool isused2[40];  // / 방향 대각선 체크
bool isused3[40];  // \ 방향 대각선 체크

void backtracking(int x) {
    if (x == n) {    // N개의 퀸을 모두 배치한 경우
        result++;
        return;
    }
    for (int y = 0; y < n; y++) {
        if (isused1[y] || isused2[x + y] || isused3[x - y + n - 1])
            continue; // 같은 열이나 대각선에 퀸이 있는 경우 스킵
        
        // 현재 위치에 퀸 배치
        isused1[y] = true;
        isused2[x + y] = true;
        isused3[x - y + n - 1] = true;
        
        // 다음 행으로 이동
        backtracking(x + 1);
        
        // 배치 해제 (백트래킹)
        isused1[y] = false;
        isused2[x + y] = false;
        isused3[x - y + n - 1] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    backtracking(0);    // 첫번째 행부터 시작
    cout << result;     // 가능한 경우의 수 출력
    return 0;
}
