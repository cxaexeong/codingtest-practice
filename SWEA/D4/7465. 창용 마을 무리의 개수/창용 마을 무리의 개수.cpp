#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> parent;

void makeSet(int n) {

	parent.resize(n + 1);
	for (int i = 1; i <= n; i++)
		parent[i] = i;

}

int find(int x) {

	if (parent[x] == x)
		return x;

	return parent[x] = find(parent[x]);
}

void unite(int x, int y) {

	int px = find(x);
	int py = find(y);

	if (px != py)
		parent[py] = px;

}

int main() {

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {

		int n, m;
		cin >> n >> m;
		makeSet(n);

		for (int i = 1; i <= m; i++) {
			int a, b;
			cin >> a >> b;
			unite(a, b);
		}

		// 서로 다른 루트의 개수 = 무리 개수
		set<int> groups;
		for (int i = 1; i <= n; i++)
			groups.insert(find(i));
		
		cout << "#" << tc << " " << groups.size() << '\n';
	}

}