// boj 14442 벽 부수고 이동하기2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX (1000+100)

int N, M, K;
int MAP[MAX][MAX];
int visit[11][MAX][MAX];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

struct RC
{
	int crash;
	int r;
	int c;
};

RC queue[MAX * MAX * 11];

void input() {

	scanf("%d %d %d", &N, &M, &K);

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			scanf("%1d", &MAP[r][c]);
		}
	}
}

int bfs(int r, int c) {

	int rp, wp;

	rp = wp = 0;

	queue[wp].r = r;
	queue[wp++].c = c;
	visit[0][r][c] = 1;

	while (rp < wp) {

		RC out = queue[rp++];

		if (out.r == N && out.c == M)
			return visit[out.crash][out.r][out.c];

		for (int i = 0; i < 4; i++) {

			int nr = out.r + dr[i];
			int nc = out.c + dc[i];

			if (nr < 1 || nc < 1 || nr > N || nc > M) continue;

			// 벽을 K번 미만으로 부순 경우
			if (out.crash < K)
			{
				// 다음 MAP 좌표 값이 벽이 아닌 경우(0)
				if (MAP[nr][nc] == 0 && visit[out.crash][nr][nc] == 0)
				{
					queue[wp].r = nr;
					queue[wp].c = nc;
					queue[wp++].crash = out.crash;

					visit[out.crash][nr][nc] = visit[out.crash][out.r][out.c] + 1;
				}
				// 다음 MAP 좌표 값이 벽인 경우(1)
				else
				{
					if (MAP[nr][nc] == 1 && visit[out.crash+1][nr][nc] == 0)
					{
						queue[wp].r = nr;
						queue[wp].c = nc;
						queue[wp++].crash = out.crash+1;

						visit[out.crash+1][nr][nc] = visit[out.crash][out.r][out.c] + 1;
					}
				}
			}


			// 벽을 K번 부순 경우
			else
			{
				if (MAP[nr][nc] == 0 && visit[out.crash][nr][nc] == 0)
				{
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