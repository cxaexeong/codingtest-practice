// boj 4963 섬의 개수
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX (50+5)

int W, H;

int MAP[MAX][MAX];
bool visit[MAX][MAX];

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct RC
{
	int r;
	int c;
};

RC queue[MAX * MAX];

void input() {

	scanf("%d %d", &W, &H);

	for (int r = 0; r <= H+1; r++) {
		for (int c = 0; c <= W+1; c++) {
			MAP[r][c] = visit[r][c] = 0;
		}
	}

	for (int r = 1; r <= H; r++) {
		for (int c = 1; c <= W; c++) {
			scanf("%d", &MAP[r][c]);
		}
	}
}

void bfs(int r, int c) {

	int rp, wp;
	
	rp = wp = 0;

	queue[wp].r = r;
	queue[wp++].c = c;

	visit[r][c] = true;

	while (rp < wp) {

		RC out = queue[rp++];

		for (int i = 0; i < 8; i++) {
			
			int nr, nc;

			nr = out.r + dr[i];
			nc = out.c + dc[i];

			if (MAP[nr][nc] == 0 || visit[nr][nc] == true) continue;

			queue[wp].r = nr;
			queue[wp++].c = nc;

			visit[nr][nc] = true;
		}
	}
}

int main() {

	while (1) {

		input();

		if (W == 0 && H == 0) break;

		int ansCount = 0;
		for (int r = 1; r <= H; r++) {
			for (int c = 1; c <= W; c++) {
				if (MAP[r][c] == 1 && visit[r][c] == false) {
					bfs(r, c);
					ansCount++;
				}
			}
		}
		printf("%d\n", ansCount);
	}
	return 0;
}
