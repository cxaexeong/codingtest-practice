#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> vec;
int arr[10];

void backtracking(int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < n; i++) {    // 중복 허용하므로 항상 0부터 탐색
        arr[depth] = vec[i];         // 현재 숫자 선택
        backtracking(depth+1);       // 다음 깊이로 이동
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    vec.resize(n);
    
    for(int i = 0; i < n; i++) 
        cin >> vec[i];
    
    sort(vec.begin(), vec.end());
    backtracking(0);
    return 0;
}