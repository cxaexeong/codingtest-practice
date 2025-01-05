#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;    // 큐 크기 n, 뽑아낼 숫자 개수 k
    
    deque<int> dq;
    vector<int> targets(k);
    
    // 1부터 n까지의 숫자를 dq에 넣음
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }
    
    // 목표 숫자 입력 받음
    for (int i = 0; i < k; i++) {
        cin >> targets[i];
    }
    
    int totalRotations = 0; // 총 회전 횟수
    
    for (int target : targets) {
        // target이 dq에 어느 방향에 있는지 찾음
        int idx = find(dq.begin(), dq.end(), target) - dq.begin();
        
        // 왼쪽 회전수와 오른쪽 회전수 계산
        int leftRotations = idx;
        int rightRotations = dq.size() - idx;
        
        // 최소 회전 수 선택
        totalRotations += min(leftRotations, rightRotations);
        
        // 실제 deque 회전 수행
        if (leftRotations <= rightRotations) {
            // 왼쪽으로 회전
            while (leftRotations--) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            // 오른쪽으로 회전
            while (rightRotations--) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        
        // target 숫자 제거
        dq.pop_front();
    }
    
    cout << totalRotations << endl;
    return 0;    
}
