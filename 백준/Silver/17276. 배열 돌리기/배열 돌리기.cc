#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX (550)

int T, N, D;
int MAP[MAX][MAX];
int temp[MAX][MAX];

void input() {
	scanf("%d %d", &N, &D);

	//D = (D + 360) % 360;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			scanf("%d", &MAP[r][c]);
		}
	}
}

void printMap() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			printf("%d ", MAP[r][c]);
		}
		putchar('\n');
	}
}

void copyMAP(int copy[MAX][MAX], int original[MAX][MAX]) {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			copy[r][c] = original[r][c];
		}
	}
}

void rotate45() { // 시계방향
	copyMAP(temp, MAP);

	// temp값을 회전시키면서 MAP에 다시 옮김
	int arr[MAX] = { 0 };
	int half = (N + 1) / 2;

	for (int c = 1; c <= N; c++) arr[c] = temp[half][c];
	for (int i = 1; i <= N; i++) MAP[i][i] = arr[i];

	for (int i = 1; i <= N; i++) arr[i] = temp[i][i];
	for (int r = 1; r <= N; r++) MAP[r][half] = arr[r];

	for (int r = 1; r <= N; r++) arr[r] = temp[r][half];
	for (int i = 1; i <= N; i++) MAP[i][N - i + 1] = arr[i];

	for (int i = 1; i <= N; i++) arr[i] = temp[N - i + 1][i];
	for (int c = 1; c <= N; c++) MAP[half][c] = arr[c];
}

void rotateCounter45() { // 반시계방향
	copyMAP(temp, MAP);

	int arr[MAX] = { 0 };
	int half = (N + 1) / 2;
	for (int i = 1; i <= N; i++) arr[i] = temp[i][i];
	for (int c = 1; c <= N; c++) MAP[half][c] = arr[c];

	for (int r = 1; r <= N; r++) arr[r] = temp[r][half];
	for (int i = 1; i <= N; i++) MAP[i][i] = arr[i];

	for (int i = 1; i <= N; i++) arr[i] = temp[i][N - i + 1];
	for (int r = 1; r <= N; r++) MAP[r][half] = arr[r];

	for (int c = 1; c <= N; c++) arr[c] = temp[half][c];
	for (int i = 1; i <= N; i++) MAP[N - i + 1][i] = arr[i];

}


int main() {
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		input();

		// 회전
		int count = D / 45;
		//for (int c = 0; c < count; c++) rotateClockise();
		if (count > 0) {
			for (int c = 0; c < count; c++) rotate45();
		}
		else {
			for (int c = 0; c < -count; c++) rotateCounter45();
		}

		printMap();
	}

	return 0;
}