/// 중복 수열 제거: 백트래킹 단계에서 last 변수를 사용해 직전에 선택한 숫자와 동일한 숫자는 건너뜀
/// 중복 선택 허용: 현재 단계에서 모든 숫자를 선택할 수 있으므로 i+1로 시작점 갱신x
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
vector<int> vec;

void backtracking(int depth) {
    if (depth == m) { // 수열의 길이가 m이 되면 출력
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int last = -1; // 중복 방지를 위한 변수
    for (int i = 0; i < n; i++) {
        if (vec[i] != last) { // 중복된 숫자는 건너뜀
            arr[depth] = vec[i];
            backtracking(depth + 1); // 중복 선택을 허용하므로 i+1로 갱신하지 않음
            last = vec[i]; // 마지막 선택한 숫자 기록
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vec.resize(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end()); // 오름차순 정렬
    backtracking(0); // 백트래킹 시작
    return 0;
}
