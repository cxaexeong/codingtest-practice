#include <bits/stdc++.h>
using namespace std;

string cogwheel[4];

void go(int x, int dir) {
    int dirs[4] = {};
    dirs[x] = dir;
    int idx = x;
    
    // 왼쪽 회전
    while (idx > 0 && cogwheel[idx][6] != cogwheel[idx-1][2]) {
        dirs[idx-1] = -dirs[idx];
        idx--;
    }
    
    while (idx < 3 && cogwheel[idx][2] != cogwheel[idx+1][6]) {
        dirs[idx+1] = -dirs[idx];
        idx++;
    }
    
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
    
    for (int i = 0; i < 4; i++)
        cin >> cogwheel[i];
    int k;
    cin >> k;
    while (k--) {
        int x, dir;
        cin >> x >> dir;
        go(x-1, dir);
    }
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        if (cogwheel[i][0] == '1')
            ans += (1 << i);  
    }
    cout << ans;
    return 0;   
}