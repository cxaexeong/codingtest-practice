// boj 2667 단지번호 붙이기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX (25+5)

int N;

int MAP[MAX][MAX];
bool visit[MAX][MAX];

int ans[MAX * MAX];

struct  RC
{
	int r;
	int c;
};

RC queue[MAX * MAX];

// 상 우 하 좌
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void input() {

	scanf("%d", &N);

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			scanf("%1d", &MAP[r][c]);
		}
	}
}

int BFS(int r, int c) {

	int rp, wp, count;

	rp = wp = 0;

	queue[wp].r = r;
	queue[wp++].c = c;

	visit[r][c] = true;
	count = 1;

	while (rp < wp) {

		RC out = queue[rp++];

		for (int i = 0; i < 4; i++) {

			int nr, nc;

			nr = out.r + dr[i];
			nc = out.c + dc[i];

			if (MAP[nr][nc] == 0 || visit[nr][nc] == true) continue;

			queue[wp].r = nr;
			queue[wp++].c = nc;

			visit[nr][nc] = true;
			count++;
		}
	}

	return count; // wp 자체가 이미 카운팅하고 있어서 동일함
}

int main() {

	input();

	// 구현
	int ansCount = 0;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (MAP[r][c] == 1 && visit[r][c] == false) {
				ans[ansCount++] = BFS(r, c);
			}
		}
	}
	printf("%d\n", ansCount);

	// 단지내 오름차순 출력을 위해 정렬
	for (int i = 0; i < ansCount - 1; i++) {
		for (int k = i + 1; k < ansCount; k++) {
			if (ans[i] > ans[k]) {
				int tmp = ans[i];
				ans[i] = ans[k];
				ans[k] = tmp;
			}
		}
	}

	for (int i = 0; i < ansCount; i++)
		printf("%d\n", ans[i]);

	return 0;
}