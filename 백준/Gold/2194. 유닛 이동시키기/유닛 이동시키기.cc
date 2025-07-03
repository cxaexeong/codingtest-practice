// boj 2194 유닛 이동시키기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX (500+50)

int N, M, A, B, K;
int sr, sc, er, ec;
int MAP[MAX][MAX];
int visit[MAX][MAX];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

struct RC
{
	int r;
	int c;
};

RC queue[MAX * MAX];

void input() {

	scanf("%d %d %d %d %d", &N, &M, &A, &B, &K);

	// 장애물 = 1로 표시
	for (int k = 0; k < K; k++) {
		int r, c;
		scanf("%d %d", &r, &c);
		MAP[r][c] = 1;
	}

	scanf("%d %d %d %d", &sr, &sc, &er, &ec);
}

bool isEmpty(int sr, int sc) {

	for (int r = sr; r <= sr + A -1; r++) {
		for (int c = sc; c <= sc + B -1; c++) {
			if (MAP[r][c] == 1) return false;
		}
	}
	return true;
}

int bfs(int r, int c) {

	int rp, wp;

	rp = wp = 0;

	visit[r][c] = 1;
	queue[wp].r = r;
	queue[wp++].c = c;

	while (rp < wp) {

		RC out = queue[rp++];

		if (out.r == er && out.c == ec)
			return visit[out.r][out.c] - 1;

		for (int i = 0; i < 4; i++) {

			int nr = out.r + dr[i];
			int nc = out.c + dc[i];

			if (isEmpty(nr, nc) == false || visit[nr][nc] != 0) continue;
			if (nr < 1 || nc < 1 || (nr + A - 1) > N || (nc + B - 1) > M) continue;
			
			queue[wp].r = nr;
			queue[wp++].c = nc;
			
			visit[nr][nc] = visit[out.r][out.c] + 1;
		}
	}
	return -1;
}

int main() {

	input();

	printf("%d\n", bfs(sr, sc));

	return 0;

}
