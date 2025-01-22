// 백트래킹 과정에서 중복된 조합을 건너뜀
// 이전에 선택된 숫자보다 같은 숫자이거나 더 큰 숫자만 선택하여 오름차순 유지
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
//bool v[10];
vector<int> vec;

void backtracking(int depth, int start) {
    if (depth == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    
    int last = -1;
    for (int i = start; i < n; i++) {
        if (vec[i] != last) {
            arr[depth] = vec[i];
            backtracking(depth+1, i+1); // i + 1로 시작점 갱신
            last = vec[i];
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
    backtracking(0,0);
    return 0;
}