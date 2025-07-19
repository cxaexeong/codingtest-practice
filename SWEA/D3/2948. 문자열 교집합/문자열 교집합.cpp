#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, M;
		cin >> N >> M;

		unordered_set<string> setA;
		string tmp;

		for (int n = 0; n < N; n++) {
			cin >> tmp;
			setA.insert(tmp);
		}

		int count = 0;
		
		for (int m = 0; m < M; m++) {
			cin >> tmp;
			if (setA.count(tmp)) count++;
		}

		cout << "#" << tc << " " << count << '\n';
	}
	return 0;
}