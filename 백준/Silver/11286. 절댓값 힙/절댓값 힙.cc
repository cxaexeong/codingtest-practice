#include <bits/stdc++.h>
using namespace std;

// 사용자 정의 비교 함수(절대값 기준 정렬, 같으면 원래 값 비교) 
struct cmp {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) return a > b; // 절대값이 같으면 원래 값이 작은순
        return abs(a) > abs(b); // 절대값 기준 정렬
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,x;
    cin >> n;
    
    priority_queue<int, vector<int>, cmp> pq;
  
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0) {
            if (pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }
    return 0;
}