#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    vector<long long> results(tc);

    for (int t = 0; t < tc; t++) {
        long long n;
        cin >> n;

        long long D = 1 + 8 * n;  // 판별식 D = 1 + 8n
        long long sqrtD = (long long) sqrt(D);

        if (sqrtD * sqrtD != D) {
            results[t] = -1;
            continue;
        }

        long long k = (-1 + sqrtD) / 2;
        if (k * (k + 1) / 2 == n) {
            results[t] = k;
        } else {
            results[t] = -1;
        }
    }

    // 한 번에 출력
    for (int t = 0; t < tc; t++) {
        cout << "#" << (t + 1) << " " << results[t] << "\n";
    }

    return 0;
}