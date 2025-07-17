#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    vector<ll> results(T+1);
    
    for (int tc = 1; tc <= T; tc++) {
        ll N;
        cin >> N;

        ll D = 1 + 8 * N;
        ll sqrtD = (ll) sqrt(D);

        if (sqrtD * sqrtD != D) {
            results[tc] = -1;
            continue;
        }

        ll k = (-1 + sqrtD) / 2;
        if (k * (k + 1) / 2 == N) {
            results[tc] = k;
        } else {
            results[tc] = -1;
        }
    }

    for (int tc = 1; tc <= T; tc++) {
        cout << "#" << tc << ' ' << results[tc] << '\n';
    }
    return 0;
}