#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX (8 + 8)

int N, M;
int num_of_cases[MAX];

int numbers[MAX];

void printCases() {

	for (int i = 0; i < M; i++) {
		printf("%d ", num_of_cases[i]);
	}
	putchar('\n');
}

void dfs(int depth, int start) {

	if (depth == M) {
		printCases();
		return;
	}

	for (int i = start; i <= N; i++) {
		num_of_cases[depth] = numbers[i];
		dfs(depth + 1, i);
	}
}

int main() {

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d ", &numbers[i]);
	}

	// 정렬
	for (int i = 1; i <= N; i++) {
		for (int k = i + 1; k <= N; k++) {
			if (numbers[i] > numbers[k]) {
				int tmp = numbers[i];
				numbers[i] = numbers[k];
				numbers[k] = tmp;
			}
		}
	}

	dfs(0, 1);

	return 0;
}