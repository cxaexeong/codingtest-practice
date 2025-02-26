#include <bits/stdc++.h>
using namespace std;

int k, n;
vector<long long> lan;

bool check(long long mid) {
    long long count = 0;
    for (long long l : lan) {
        count += l / mid;
    }
    return count >= n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    lan.resize(k);
    for (int i = 0; i < k; i++) cin >> lan[i];

    long long st = 1, en = *max_element(lan.begin(), lan.end());
    long long ans = 0;

    while (st <= en) {
        long long mid = (st + en) / 2;
        if (check(mid)) {
            ans = mid;
            st = mid + 1;
        } else {
            en = mid - 1;
        }
    }

    cout << ans;
}
