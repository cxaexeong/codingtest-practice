#include <bits/stdc++.h>
using namespace std;

int t, n;
int students[100001];
bool v[100001];
bool finished[100001];
int result;

void bfs(int start) {
    queue<int> q;
    vector<int> path;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (v[current]) {
            // 이미 방문한 노드에 도달했을 경우
            if (!finished[current]) {
                // 사이클에 포함된 노드 계산
                int node = current;
                int cycle_size = 0;

                do {
                    cycle_size++;
                    node = students[node];
                } while (node != current);

                result -= cycle_size; // 사이클 크기만큼 제외
            }
            // 탐색 종료
            break;
        }

        v[current] = true;
        path.push_back(current);
        q.push(students[current]);
    }

    // 탐색 완료 후 경로를 finished로 설정
    for (int node : path) {
        finished[node] = true;
    }
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
                bfs(i);
            }
        }

        cout << result << endl;
    }

    return 0;
}