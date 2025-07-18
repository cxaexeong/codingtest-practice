#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define x first
#define y second
#define MAX (100+10)

using namespace std;

int N;
int MAP[MAX][MAX];
int dist[MAX][MAX];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int bfs() {

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	dist[0][0] = MAP[0][0]; 

	while (!q.empty()) {

		pair<int, int> cur = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {

			int nr = cur.x + dr[d];
			int nc = cur.y + dc[d];

			if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;

			int newCost = dist[cur.x][cur.y] + MAP[nr][nc];

			if (newCost < dist[nr][nc]) {
				dist[nr][nc] = newCost;
				q.push({ nr, nc });
			}
		}
	}
	return dist[N - 1][N - 1];
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;

			for (int j = 0; j < N; j++) {
				MAP[i][j] = str[j] - '0';
				dist[i][j] = INT_MAX;
			}
		}

		int ans = bfs();
		cout << "#" << tc << " " << ans << '\n';
	}

	return 0;
}