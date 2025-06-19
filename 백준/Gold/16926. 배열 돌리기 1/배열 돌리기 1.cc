#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX (330)

int N, M, R;
int MAP[MAX][MAX];
int temp[MAX][MAX];

struct  RC 
{
	int r;
	int c;
};

RC arr[MAX * MAX];

void input() {

	scanf("%d %d %d", &N, &M, &R);

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			scanf("%d", &MAP[r][c]);
		}
	}
}

void copyMAP(int copy[MAX][MAX], int original[MAX][MAX]) {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			copy[r][c] = original[r][c];
		}
	}
}

void printMAP() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			printf("%d ", MAP[r][c]);
		}
		putchar('\n');
	}
}

void rotateStep(int sr, int sc, int n, int m, int rotateCount) {
	int er, ec;

	//sr = sc = 1;
	er = sr + n - 1;
	ec = sc + m - 1;

	copyMAP(temp, MAP);

	int index = 0;
	// red
	for (int c = sc; c <= ec; c++) {
		arr[index].r = sr;
		arr[index].c = c;
		index++;
	}

	// blue
	for (int r = sr + 1; r <= er; r++) {
		arr[index].r = r;
		arr[index].c = ec;
		index++;
	}

	// yellow
	for (int c = ec - 1; c >= sc; c--) {
		arr[index].r = er;
		arr[index].c = c;
		index++;
	}

	// green
	for (int r = er - 1; r >= sr + 1; r--) {
		arr[index].r = r;
		arr[index].c = sc;
		index++;
	}

	// 반시계 방향 이동
	for (int i = 0; i < index; i++) {

		int newIndex = (i - rotateCount) % index;

		newIndex = newIndex < 0 ? newIndex + index : newIndex;

		RC front = arr[newIndex];
		MAP[front.r][front.c] = temp[arr[i].r][arr[i].c];
	}
}

void rotate(int rotateCount) {
	int sr, sc, n, m;
	int step = N < M ? N / 2 : M / 2;

	sr = sc = 1;
	n = N, m = M;
	for (int s = 0; s < step; s++) {
		rotateStep(sr, sc, n, m, rotateCount);
		sr++, sc++; // 첫번째 네모 다 돌린 후(1,1) -> (2,2)
		n -= 2, m -= 2;
	}
}

int main() {
	input();

	rotate(R);

	printMAP();

	return 0;
}