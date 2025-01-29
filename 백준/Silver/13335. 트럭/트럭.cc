#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w, l;
    cin >> n >> w >> l;
    
    vector<int> weight(n);
    for (int i = 0; i < n; i++) 
        cin >> weight[i];

    queue<pair<int, int>> q;  // (트럭 무게, 다리 진입 시간)
    int time = 0, current_weight = 0, index = 0;

    while (index < n || !q.empty()) {
        // 1. 다리에서 빠져나갈 트럭 확인
        if (!q.empty() && q.front().second + w == time) {
            current_weight -= q.front().first;  // 트럭 무게 제거
            q.pop();
        }

        // 2. 새로운 트럭 추가 가능 여부 확인
        if (index < n && current_weight + weight[index] <= l) {
            q.push({weight[index], time});  // 트럭 진입
            current_weight += weight[index];  // 현재 다리 하중 증가
            index++;  // 다음 트럭 진행
        }

        time++;  // 1초 증가
    }

    cout << time << '\n';  // 모든 트럭이 다리를 건너는 데 걸린 시간 출력
}
