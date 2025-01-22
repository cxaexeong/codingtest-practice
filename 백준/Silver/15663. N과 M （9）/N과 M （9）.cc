// 백트래킹 과정에서 직전에 선택한 숫자와 같은 숫자는 건너뜀
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool v[10];
vector<int> vec;

void backtracking(int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        return;        
    }
    
    int last = -1;                     // 중복 방지를 위한 변수
    for (int i = 0; i < n; i++) {
        if (!v[i] && vec[i] != last) { // 방문x, 이전 값과 다르면 선택
            v[i] = true;
            arr[depth] = vec[i];
            backtracking(depth + 1);
            v[i] = false;
            last = vec[i];            // 마지막 선택한 값 갱신
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    vec.resize(n); // vec 크기 조정
    
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    
    sort(vec.begin(), vec.end());
    backtracking(0);
    return 0;    
}