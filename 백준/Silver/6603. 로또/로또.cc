#include <bits/stdc++.h>
using namespace std;

int k;
vector<int> s;
int arr[6];

void backtracking(int depth, int start) {
    if (depth == 6) {
        for (int i = 0; i < 6; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i = start; i < k; i++) {
        arr[depth] = s[i];
        backtracking(depth+1, i+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (true) {
        cin >> k;
        if (k == 0) break;
        
        s.clear();
        s.resize(k);
        for (int i = 0; i < k; i++)
            cin >> s[i];
        
        backtracking(0,0);
        cout << '\n';            // 테스트케이스 사이에 빈 줄 출력
        
    }
}