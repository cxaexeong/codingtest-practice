#include <bits/stdc++.h>
using namespace std;

int t, n;
int students[100001];
bool v[100001];
bool finished[100001];
int result;

void dfs(int current) {
    v[current] = true;
    int next = students[current];

    if (!v[next]) {
        dfs(next);
    } else if (!finished[next]) {
        // 사이클 발견: next가 아직 탐색 완료되지 않은 노드일 경우
        int node = next;
        int cycle_size = 0;

        do {
            cycle_size++;
            node = students[node];
        } while (node != next);

        result -= cycle_size; // 사이클 크기만큼 제외
    }

    finished[current] = true; // 현재 노드 탐색 완료
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        result = n;
        memset(v, false, sizeof(v));
        memset(finished, false, sizeof(finished));

        for (int i = 1; i <= n; i++) {
            cin >> students[i];
        }

        for (int i = 1; i <= n; i++) {
            if (!v[i]) {
                dfs(i);
            }
        }

        cout << result << endl;
    }

    return 0;
}
