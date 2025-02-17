#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, age;
    string name;
    cin >> n;
    
    vector<pair<int, string>> members;
    
    for (int i = 0; i < n; i++) {
        cin >> age >> name;
        members.push_back({age, name});
    }
    
    // stable_sort를 사용하여 나이(age)기준 오름차순 정렬(입력 순서 유지)
    stable_sort(members.begin(), members.end(), [](const pair<int, string> &a, const pair<int, string> &b) {
        return a.first < b.first; // 나이 기준 정렬
    });
    
    for (const auto &m : members) {
        cout << m.first << " " << m.second << '\n';
    }
    return 0;
}