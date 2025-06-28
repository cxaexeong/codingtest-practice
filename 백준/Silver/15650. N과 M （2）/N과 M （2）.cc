#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX (8+8)

int N, M;
int num_of_cases[MAX];

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
		num_of_cases[depth] = i;
		dfs(depth + 1, i+1);
	}
}

int main() {

	scanf("%d %d", &N, &M);

	dfs(0, 1);
	
	return 0;
}