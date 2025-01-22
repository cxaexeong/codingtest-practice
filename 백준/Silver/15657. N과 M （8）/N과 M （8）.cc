#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
vector<int> vec;

void backtracking(int depth, int start) {
    if (depth == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i = start; i < n; i++) {
        arr[depth] = vec[i];
        backtracking(depth+1, i); // 같은 위치도(i)도 포함
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
    backtracking(0, 0); // 오름차순이기 때문에 이전에 선택한 값보다 작거나 같은 값 선택x
    return 0;
}