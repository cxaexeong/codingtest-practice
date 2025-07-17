#include <bits/stdc++.h>
using namespace std;

const int MAXW = 200000;
int W[200000];
int S[200000];
int N, K;

bool Verify(int val) {
    int idx = 0; // 현재 덩어리 인덱스
    int count = 0; // 연속 허용 블록 개수

    for (int i = 0; i < N && idx < K; ++i) {
        if (W[i] <= val) {
            count++;
            if (count == S[idx]) {
                // 현재 덩어리 배치 완료
                idx++;
                count = 0;
            }
        } else {
            count = 0; // 중단되면 연속 카운트 초기화
        }
    }
    return (idx == K); // 모든 덩어리를 배치했는지?
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> N >> K;
        for (int i = 0; i < N; ++i) cin >> W[i];
        for (int i = 0; i < K; ++i) cin >> S[i];

        int l = 0, r = MAXW;
        while (l < r) {
            int mid = (l + r) / 2;
            if (Verify(mid)) r = mid;
            else l = mid + 1;
        }

        cout << "#" << tc << " " << l << "\n";
    }

    return 0;
}
