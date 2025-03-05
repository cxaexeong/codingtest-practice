#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 정렬
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    // 1. 도난당한 학생 중 여벌이 있는 학생 제거
    vector<int> real_lost;
    set<int> reserve_set(reserve.begin(), reserve.end());
    
    for (int student : lost) {
        if (reserve_set.count(student)) {
            reserve_set.erase(student);
        } else {
            real_lost.push_back(student);
        }
    }
    
    // 2. 체육복 빌려주기
    int ans = n - real_lost.size();
    
    for (int student : real_lost) {
        if (reserve_set.count(student-1)) {
            reserve_set.erase(student-1);
            ans++;
        } else if (reserve_set.count(student+1)) {
            reserve_set.erase(student+1);
            ans++;
        }
    }
    return ans;
}