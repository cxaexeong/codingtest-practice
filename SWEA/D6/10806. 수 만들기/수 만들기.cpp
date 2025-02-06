#include <iostream>
#include <queue>
#define x first
#define y second

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        int N, K;
        cin >> N;

        int Nums[11];
        for (int i = 0; i < N; i++) {
            cin >> Nums[i];
        }
        cin >> K;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, K));

        while (pq.top().y) {
            pair<int, int> cur = pq.top();
            pq.pop();

            pq.push(make_pair(cur.x + cur.y, 0));
            for (int i = 0; i < N; i++) {
                pq.push(make_pair(cur.x + cur.y % Nums[i], cur.y / Nums[i]));
            }
        }

        cout << "#" << t << " " << pq.top().x << "\n";
    }

    return 0;
}
