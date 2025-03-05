#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int n = name.size();
    int answer = 0;
    int turn = n - 1; // 커서 이동 최솟값 (기본적으로 오른쪽 이동)

    for (int i = 0; i < n; i++) {
        // 1. 알파벳 변경 최소 횟수 계산
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        // 2. 커서 이동 최적화 (A가 연속된 곳을 고려)
        int nxt = i + 1;
        while (nxt < n && name[nxt] == 'A') nxt++; // A가 연속되면 건너뛰기

        // "순방향으로 가다가 다시 돌아오는 경우" vs "반대로 가는 경우"
        turn = min(turn, i + n - nxt + min(i, n - nxt));
    }

    return answer + turn;
}
