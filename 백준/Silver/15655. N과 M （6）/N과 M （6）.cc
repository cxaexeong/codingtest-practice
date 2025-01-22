#include <bits/stdc++.h>
using namespace std;

vector<int> vec; // 입력 숫자 저장
int arr[10];     // 조합 저장
bool v[10];      // 방문 여부 체크
int n, m;

void backtracking(int depth, int start) {
    if (depth == m) { // 깊이가 m에 도달하면 결과 출력
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < n; i++) { // start부터 시작해 오름차순 유지
        if (!v[i]) {
            v[i] = true;
            arr[depth] = vec[i]; // vec의 값을 arr에 저장
            backtracking(depth + 1, i + 1); // 다음 숫자는 i + 1부터 탐색
            v[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m; // n개의 숫자와 m개 선택
    
    vec.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i]; // 입력 숫자 저장
    }
    sort(vec.begin(), vec.end()); // 오름차순 정렬
    
    backtracking(0, 0); // 백트래킹 시작
    return 0;
}
