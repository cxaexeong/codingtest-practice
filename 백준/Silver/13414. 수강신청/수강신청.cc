#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k, l;
    cin >> k >> l;

    unordered_map<string, int> lastApplication;  // {학번: 마지막 신청 순서}
    vector<string> studentOrder;                 // 입력된 학번 순서 저장

    for (int i = 0; i < l; i++) {
        string id;
        cin >> id;

        // 처음 신청한 학번이면 순서 저장
        if (lastApplication.find(id) == lastApplication.end()) {
            studentOrder.push_back(id);
        }

        // 최신 신청 시간 기록
        lastApplication[id] = i;
    }

    // 학생을 신청 순서대로 정렬하되, 마지막 신청한 순서만 유지
    sort(studentOrder.begin(), studentOrder.end(), [&](const string &a, const string &b) {
        return lastApplication[a] < lastApplication[b];  // 최신 신청 순서대로 정렬
    });

    // 최대 k명 출력
    int count = 0;
    for (const string &id : studentOrder) {
        cout << id << '\n';
        if (++count == k) break;
    }

    return 0;
}
