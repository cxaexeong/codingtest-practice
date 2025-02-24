#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> flowers(n);

    for (int i = 0; i < n; ++i) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        flowers[i] = {sm * 100 + sd, em * 100 + ed};
    }

    // 정렬: 시작 날짜 오름차순, 같다면 종료 날짜 내림차순
    sort(flowers.begin(), flowers.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    });

    int count = 0, lastEnd = 301, maxEnd = 301, idx = 0;

    while (lastEnd <= 1130) {
        bool found = false;

        // 현재 lastEnd 이하로 시작하는 꽃들 중 가장 늦게까지 피어있는 꽃 찾기
        while (idx < n && flowers[idx].first <= lastEnd) {
            maxEnd = max(maxEnd, flowers[idx].second);
            ++idx;
            found = true;
        }

        if (!found) break; // 연결할 수 있는 꽃이 없으면 종료

        ++count;
        lastEnd = maxEnd; // 가장 오래 지속되는 꽃 선택

        if (lastEnd > 1130) {
            cout << count << '\n';
            return 0;
        }
    }

    cout << 0 << '\n'; // 11월 30일까지 유지할 수 없는 경우
    return 0;
}
