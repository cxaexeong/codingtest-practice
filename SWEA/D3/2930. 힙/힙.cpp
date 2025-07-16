#include <iostream>
#include <queue> 
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		
		int N;
		cin >> N;

		priority_queue<int, vector<int>> pq;

		cout << "#" << tc;

		for (int n = 0; n < N; n++) {
			int cmd;
			cin >> cmd;

			if (cmd == 1) {
				int x;
				cin >> x;
				pq.push(x);
			}

			else if (cmd == 2) {
				if (!pq.empty()) {
					cout << " " << pq.top();
					pq.pop();
				}
				else
					cout << " -1";
			}
		}
	cout << '\n';
	}

}