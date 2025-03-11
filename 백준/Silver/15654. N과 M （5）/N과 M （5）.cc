#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;
vector<int> selected;  // 선택한 숫자를 저장할 벡터
bool isused[10];  // 숫자 사용 여부 체크

void backtracking(int depth) {
    if (depth == m) {
        for (int num : selected) cout << num << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!isused[i]) {
            isused[i] = true;
            selected.push_back(arr[i]);
            backtracking(depth+1);
            selected.pop_back();
            isused[i] = false;
        }
    }

    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    backtracking(0);
}