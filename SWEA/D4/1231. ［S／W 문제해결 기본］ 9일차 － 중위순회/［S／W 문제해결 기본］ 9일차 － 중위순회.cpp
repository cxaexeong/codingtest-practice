#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define MAX (100+10)

using namespace std;

int N;
char node[MAX];
int left_node[MAX];
int right_node[MAX];

void dfs(int cur) {
	if (cur == 0) return;

	dfs(left_node[cur]);
	cout << node[cur];
	dfs(right_node[cur]);
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int tc = 1; tc <= 10; tc++)
	{
		cin >> N;
		memset(left_node, 0, sizeof left_node);
		memset(right_node, 0, sizeof right_node);

		for (int i = 1; i <= N; i++)
		{
			int idx;
			char ch;
			cin >> idx >> ch;
			node[idx] = ch;

			// 남은 입력
			if (cin.peek() != '\n')
			{
				int l;
				cin >> l;
				left_node[idx] = l;
			}
			if (cin.peek() != '\n')
			{
				int r;
				cin >> r;
				right_node[idx] = r;
			}

		}

		cout << "#" << tc << " ";
		dfs(1);
		cout << '\n';
	}
}