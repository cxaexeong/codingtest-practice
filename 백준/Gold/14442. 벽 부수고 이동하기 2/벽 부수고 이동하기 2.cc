// boj 14442 벽 부수고 이동하기2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX (1000 + 5)

int N, M, K;
int MAP[MAX][MAX];
int visit[11][MAX][MAX];

struct RC {
	int r;
	int c;
	int crash;
};

RC queue[MAX * MAX * 11]; // 모든 좌표가 최대 1번이 아니라 2번 들어갈 수 있음

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

void input() {

	scanf("%d %d %d", &N, &M, &K);

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			scanf("%1d", &MAP[r][c]);
		}
	}
}

void printMAP(int map[MAX][MAX]) {

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			printf("%d ", map[r][c]);
		}
		putchar('\n');
	}
	putchar('\n');
}

void printMapAll() {

	printf("MAP\n");
	printMAP(MAP);

	printf("visit[0]\n");
	printMAP(visit[0]);

	printf("visit[1]\n");
	printMAP(visit[1]);

	// or visit[k]까지 출력
}

int bfs(int r, int c)
{
	int rp, wp;

	rp = wp = 0;

	visit[0][r][c] = 1;

	queue[wp].r = r;
	queue[wp++].c = c;

	// printMap();

	while (rp < wp) {
		RC out = queue[rp++];

		if (out.r == N && out.c == M) return visit[out.crash][out.r][out.c];

		for (int i = 0; i < 4; i++) {
			int nr, nc;

			nr = out.r + dr[i];
			nc = out.c + dc[i];

			if (nr < 1 || nc < 1 || nr > N || nc > M) continue;

			if (out.crash < K) { // 벽을 K번 미만 부순 경우
				if (MAP[nr][nc] == 0 && visit[out.crash][nr][nc] == 0) {
					queue[wp].r = nr;
					queue[wp].c = nc;
					queue[wp++].crash = out.crash;

					visit[out.crash][nr][nc] = visit[out.crash][out.r][out.c] + 1;
				}
				else {
					if (MAP[nr][nc] == 1 && visit[out.crash+1][nr][nc] == 0) {
						queue[wp].r = nr;
						queue[wp].c = nc;
						queue[wp++].crash = out.crash+1;

						visit[out.crash+1][nr][nc] = visit[out.crash][out.r][out.c] + 1;
					}
				}
			}
			else { // 마지막 K
				if (MAP[nr][nc] == 0 && visit[out.crash][nr][nc] == 0) {
					queue[wp].r = nr;
					queue[wp].c = nc;
					queue[wp++].crash = out.crash;

					visit[out.crash][nr][nc] = visit[out.crash][out.r][out.c] + 1;
				}
			}
		}
	}
	return -1;
}

int main() {

	input();

	printf("%d\n", bfs(1, 1));

	return 0;
}