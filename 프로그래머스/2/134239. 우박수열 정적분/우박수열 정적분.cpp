#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<int> collatz;
    vector<double> area;
    
    // 1. 콜라츠 수열 생성
    while (k != 1) {
        collatz.push_back(k);
        k = (k % 2 == 0) ? k / 2 : k * 3 + 1;
    }
    collatz.push_back(1);
    
    // 2. 사다리꼴 면적 계산
    for (int i = 0; i < collatz.size() - 1; i++) {
        double trapezoid = (collatz[i] + collatz[i+1]) / 2.0;
        area.push_back(trapezoid);
    } 
    
    // 3. 누적합 계산
    vector<double> prefixSum(collatz.size(), 0.0);
    for (int i = 1; i < collatz.size(); i++) {
        prefixSum[i] = prefixSum[i-1] + area[i-1];
    }
    
    // 4. 정적분 결과 구하기
    vector<double> ans;
    for (const auto& range : ranges) {
        int a = range[0];
        int b = collatz.size() - 1 + range[1];
        
        if (a > b) {
            ans.push_back(-1.0);
        } else {
            ans.push_back(prefixSum[b] - prefixSum[a]);
        }
    }
    return ans;
    
    
    
    
}