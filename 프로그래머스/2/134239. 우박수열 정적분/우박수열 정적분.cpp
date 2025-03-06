#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<int> collatz;    // 우박수열 저장
    vector<double> area;    // 각 구간별 면적 저장
    
    // 1. 콜라츠 수열 생성
    while (k != 1) {
        collatz.push_back(k);
        k = (k % 2 == 0) ? k / 2 : k * 3 + 1;
    }
    collatz.push_back(1);   // 마지막 1 추가
    
    int n = collatz.size() - 1;     // 마지막 인덱스
    
    // 2. 사다리꼴 면적 계산
    for (int i = 0; i < n; i++) {
        double trap_area = (collatz[i] + collatz[i+1]) / 2.0;
        area.push_back(trap_area);
    }
    
    // 3. 누적합을 활용한 구간 정적분 계산
    vector<double> prefixSum(n+1, 0.0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i-1] + area[i-1];
    }
    
    vector<double> ans;
    for (const auto& range : ranges) {
        int a = range[0];
        int b = n + range[1];
        
        if (a > b) {
            ans.push_back(-1.0);
        } else {
            ans.push_back(prefixSum[b] - prefixSum[a]);
        }
    }
    return ans;    
}