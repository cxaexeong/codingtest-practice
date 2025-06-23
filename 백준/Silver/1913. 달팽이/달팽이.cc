#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX (1110)

int N, K;
int MAP[MAX][MAX];

// 상 우 하 좌 
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

void printMAP() {

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			printf("%d ", MAP[r][c]);
		}
		putchar('\n');
	}
}

void makeSnail() {

	int ansR, ansC;
	int r, c, direction;
	int index, size; // 달팽이 숫자, 화살표 사이즈

	r = c = ansR = ansC = (N + 1) / 2;
	direction = 0;
	index = 1;
	size = 0;

	MAP[r][c] = index++;

	for (int i = 0; i < 2 * N - 1; i++) {
		if (i % 2 == 0) size++;
		// 화살표의 사이즈만큼 달팽이가 움직임
		for (int s = 0; s < size; s++) {
			int nr, nc;
			nr = r + dr[direction];
			nc = c + dc[direction];

			if (index == K) {
				ansR = nr;
				ansC = nc;
			}

			MAP[nr][nc] = index++;

			// 이동 완료했으니 좌표 갱신
			r = nr;
			c = nc;
		}
		// 한 칸 움직였으니 direction 증가
		direction++;
		if (direction == 4) direction = 0;
	}


	printMAP();
	printf("%d %d\n", ansR, ansC);

}

int main() {

	scanf("%d %d", &N, &K);

	makeSnail();

	return 0;

}