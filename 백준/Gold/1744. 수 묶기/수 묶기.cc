#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> positive, negative;
    int ones = 0, zeros = 0;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 1) positive.push_back(x); // 양수 그룹 (1 제외)
        else if (x == 1) ones++;          // 1 개수 따로 저장
        else if (x == 0) zeros++;         // 0 개수 따로 저장
        else negative.push_back(x);       // 음수 그룹
    }
    
    // 양수는 큰 것부터 정렬 (내림차순)
    sort(positive.rbegin(), positive.rend());
    // 음수는 작은 것부터 정렬 (오름차순)
    sort(negative.begin(), negative.end());
    
    int maxSum = 0;
    
    // 양수 그룹 최대 합 구하기
    for (int i = 0; i + 1 < positive.size(); i+=2) {
        maxSum += positive[i] * positive[i+1]; // 큰 수끼리 곱하기
    }
    if (positive.size() % 2 == 1) {            // 남은 수 더하기
        maxSum += positive.back();
    }
    
    // 음수 그룹 최대 합 구하기
    for (int i = 0; i + 1 < negative.size(); i+=2) {
        maxSum += negative[i] * negative[i+1]; // 작은 수끼리 곱하기
    }
    if (negative.size() % 2 == 1) {             // 남은 수 처리
        if (zeros == 0) {                       // 0이 없으면 남은 음수를 더함
            maxSum += negative.back();
        }        
    }
    
    maxSum += ones;
    cout << maxSum << '\n';
    return 0;
}