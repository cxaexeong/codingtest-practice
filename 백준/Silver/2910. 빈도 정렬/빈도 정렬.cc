#include <bits/stdc++.h>
using namespace std;

// 정렬 기준: (1) 빈도 높은 순 (2) 같은 빈도면 입력 순서 유지
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) return a.second > b.second; // 빈도 높은 순
    return false; // 입력 순서 유지
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    unordered_map<int, int> freq;  // 숫자의 빈도 저장
    vector<int> order;             // 입력 순서 저장
    unordered_map<int, int> first_pos; // 처음 등장한 위치

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (freq[x] == 0) order.push_back(x); // 처음 등장한 숫자만 저장
        freq[x]++;
        if (first_pos.find(x) == first_pos.end()) first_pos[x] = i; // 첫 등장 위치 저장
    }

    // 빈도와 첫 등장 위치를 함께 저장하여 정렬
    vector<pair<int, int>> arr;
    for (int num : order) {
        arr.push_back({num, freq[num]});
    }

    // 정렬: (1) 빈도 내림차순 (2) 처음 등장한 순서 유지
    stable_sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    });

    // 출력
    for (auto p : arr) {
        for (int i = 0; i < p.second; i++) cout << p.first << " ";
    }
    cout << '\n';

    return 0;
}
