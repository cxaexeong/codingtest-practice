#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,w,l;
    cin >> n >> w >> l;
    
    vector<int> weight(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    
    queue<pair<int,int>> q; // (트럭무게, 진입시간)
    int time = 0, current_weight = 0, index = 0;
    
    while (index < n || !q.empty()) {
        // 1. 다리에서 빠져나갈 트럭 확인
        if (q.front().second + w == time) {
            current_weight -= q.front().first;
            q.pop();
        }
        // 2. 새로운 트럭 추가 가능 여부 확인
        if (index < n && current_weight + weight[index] <= l) {
            q.push({weight[index], time});
            current_weight += weight[index];
            index++;
        }
        time++;
    }
    cout << time << '\n';
}