#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙 (N개 유지)

    for (int i = 0; i < N * N; i++) { // NxN개의 수 입력받기
        int x;
        cin >> x;
        pq.push(x);
        if (pq.size() > N) pq.pop(); // N개 초과하면 가장 작은 값 제거
    }
    
    cout << pq.top() << '\n'; // N번째 큰 값 출력
}
