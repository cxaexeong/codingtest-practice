#include <bits/stdc++.h>
using namespace std;

string cogwheel[4];

void go(int x, int dir) {
    int dirs[4] = {};
    dirs[x] = dir;
    int idx = x;
    // 왼쪽으로 회전 전파
    while (idx > 0 && cogwheel[idx][6] != cogwheel[idx-1][2]) {
        dirs[idx-1] = -dirs[idx];
        idx--;
    }
    // 오른쪽으로 회전 전파
    idx = x;
    while (idx < 3 && cogwheel[idx][2] != cogwheel[idx+1][6]) {
        dirs[idx+1] = -dirs[idx];
        idx++;
    }
    // 회전 적용
    for (int i = 0; i < 4; i++) {
        if (dirs[i] == -1) 
            rotate(cogwheel[i].begin(), cogwheel[i].begin()+1, cogwheel[i].end());
        if (dirs[i] == 1) 
            rotate(cogwheel[i].begin(), cogwheel[i].begin()+7, cogwheel[i].end());
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 톱니바퀴 상태 입력
    for (int i = 0; i < 4; i++) 
        cin >> cogwheel[i];
    
    int k;
    cin >> k;
    while (k--) {
        int x, dir;
        cin >> x >> dir;
        go(x-1, dir); // 1-based index를 0-based index로 변환
    }
    
    // 점수 계산
    int ans = 0;
    for (int i = 0; i < 4; i++) 
        if (cogwheel[i][0] == '1')
            ans += (1 << i);
    cout << ans;
    return 0;
}
