#include <iostream>
#include <cstring>
const int MAX = 101;
using namespace std;

int arr[MAX][MAX];
bool visited[MAX];

int n;

void dfs(int v) {
	for (int i = 0; i < n; i++) {
		if (!visited[i] && arr[v][i]) {
			//최초 시작 노드는 방문을 체크해주면 안되니 
			//방문 여부를 그 다음 노드부터 체크하도록 해줌
			visited[i] = true;
			dfs(i); 
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		memset(visited, false, MAX);
		dfs(i);
		for (int j = 0; j < n; j++) {
			if (visited[j]) arr[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}