#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
vector<int> vec; 
bool v[10];

void backtracking(int depth) {
    if (depth == m) {   // 종료 조건: 수열의 길이가 m에 도달
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < n; i++) {  // 0부터 시작
        if (!v[i]) {
            v[i] = true;
            arr[depth] = vec[i];
            backtracking(depth + 1);
            v[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    vec.resize(n);  // 벡터 크기 설정
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    sort(vec.begin(), vec.end());  // 오름차순 정렬
    backtracking(0);               // 백트래킹 시작
    return 0;
}
