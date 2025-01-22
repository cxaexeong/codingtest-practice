#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
vector<int> vec;

void backtracking(int depth, int start) {
    if (depth == m) {
        for (int i = 0; i < m; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        return; // 깊이가 m에 도달했으면 종료
    }
    
    int last = -1; // 중복 방지를 위한 변수
    for (int i = start; i < n; i++) {
        if (vec[i] != last) { // 직전에 선택한 값과 다른 경우만 처리
            arr[depth] = vec[i];
            backtracking(depth + 1, i); // 같은 숫자를 선택할 수 있도록 i 유지
            last = vec[i]; // 마지막 선택한 값 갱신
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    vec.resize(n);
    
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    backtracking(0, 0);
    return 0;
}
