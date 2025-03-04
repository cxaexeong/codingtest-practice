#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    vector<int> nums;    // 숫자 그룹의 합 저장
    string temp = "";
    int sum = 0;
    bool minusFlag = false;    // "-" 이후의 숫자 그룹을 추적
    
    for (char c : s) {
        if (c == '-' || c == '+') {
            sum += stoi(temp);    // 현재 숫자를 sum에 추가
            temp = "";            // temp 초기화 
            if (c == '-') {
                if (minusFlag) nums.push_back(-sum);    // "-"이후 그룹이면 음수 처리
                else nums.push_back(sum);               // 첫 번째 그룹은 양수로 저장
                sum = 0;
                minusFlag = true;                       // 이후 모든 값은 "-"그룹에 포함
            }
        } else {
            temp += c; // 숫자를 문자열로 누적
        }
    }
    
    // 마지막 숫자 처리
    sum += stoi(temp);
    if (minusFlag) nums.push_back(-sum);
    else nums.push_back(sum);
    
    // 최종 계산 결과
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        result += nums[i];
    }
    
    cout << result << '\n';
    return 0;
}