// boj 2234 성곽
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX (50+5)

#define LEFT (0)
#define UP (1)
#define RIGHT (2)
#define DOWN (3)

int N, M;
int MAP[MAX][MAX];
int visit[MAX][MAX];

int answer[MAX * MAX];

// 서, 북, 동, 남
int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};

struct RC
{
	int r;
	int c;
};

RC queue[MAX * MAX];

int WALL[16 + 3][5] = {
	{ 0, 0, 0, 0 },
	{ 1, 0, 0, 0 },
	{ 0, 1, 0, 0 },
	{ 1, 1, 0, 0 },
	{ 0, 0, 1, 0 },
	{ 1, 0, 1, 0 },
	{ 0, 1, 1, 0 },
	{ 1, 1, 1, 0 },
	{ 0, 0, 0, 1 },
	{ 1, 0, 0, 1 },
	{ 0, 1, 0, 1 },
	{ 1, 1, 0, 1 },
	{ 0, 0, 1, 1 },
	{ 1, 0, 1, 1 },
	{ 0, 1, 1, 1 },
	{ 1, 1, 1, 1 },
};

void input() {

	scanf("%d %d", &M, &N);

	// init
	for (int r = 0; r <= N + 1; r++) 
		for (int c = 0; c <= M + 1; c++)
			MAP[r][c] = 15;
	
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= M; c++)
			scanf("%d", &MAP[r][c]);

}

int isOpen(int room1, int room2, int direction)
{
	if (direction == LEFT)
		return !(WALL[room1][LEFT] || WALL[room2][RIGHT]);

	if (direction == UP)
		return !(WALL[room1][UP] || WALL[room2][DOWN]);

	if (direction == RIGHT)
		return !(WALL[room1][RIGHT] || WALL[room2][LEFT]);

	if (direction == DOWN)
		return !(WALL[room1][DOWN] || WALL[room2][UP]);

	return -1; // error
}

int bfs(int r, int c, int mark) {

	int rp, wp;

	rp = wp = 0;

	queue[wp].r = r;
	queue[wp++].c = c;

	visit[r][c] = mark;

	while (rp < wp) {

		RC out = queue[rp++];

		for (int i = 0; i < 4; i++) {
			int nr = out.r + dr[i];
			int nc = out.c + dc[i];

			if (isOpen(MAP[out.r][out.c], MAP[nr][nc], i) == 0 ||
				visit[nr][nc] != 0) continue;

			queue[wp].r = nr;
			queue[wp++].c = nc;
			visit[nr][nc] = mark;
		}
	}
	return wp;
}

void printMap() // for debug
{
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= M; c++)
			printf("%d ", MAP[r][c]);
		putchar('\n');
	}
	putchar('\n');

	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= M; c++)
			printf("%d ", visit[r][c]);
		putchar('\n');
	}
	putchar('\n');
}


int main() {

	int answerCount, mark, maxAnswer, maxAreaSum;

	input();

	answerCount = 1;
	mark = 1; 

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			if (visit[r][c] == 0)
				answer[answerCount++] = bfs(r, c, mark++);
		}
	}

	maxAnswer = 0;
	for (int i = 1; i <= answerCount; i++) {
		if (maxAnswer < answer[i])
			maxAnswer = answer[i];
	}

	maxAreaSum = 0; 
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (visit[r][c] == visit[nr][nc]) continue;

				int tmpArea = answer[visit[r][c]] + answer[visit[nr][nc]];
				if (maxAreaSum < tmpArea) maxAreaSum = tmpArea;
			}
		}
	}

	printf("%d\n%d\n%d\n", answerCount - 1, maxAnswer, maxAreaSum);
	//printMap();
	return 0;
}
