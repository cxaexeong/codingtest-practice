#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX (8+8)

int N, M;

int num_of_cases[MAX];
bool visit[MAX];
int numbers[MAX];

int maxAns;

void printCases() {

	for (int i = 0; i < M; i++) {
		printf("%d ", num_of_cases[i]);
	}
	putchar('\n');
}

int abs(int x) {
	return x > 0 ? x : -x;
}

int calculate() {
	int sum = 0;
	for (int i = 0; i < N - 1; i++) {
		sum += abs((num_of_cases[i] - num_of_cases[i + 1]));
	}
	return sum;
}

void dfs(int depth) {

	if (depth == N) {
		//printCases();
		int tmp = calculate();
		if (maxAns < tmp) maxAns = tmp;
		return;
	}

	for (int i = 0; i < N; i++) {
		
		if (visit[i] == true) continue;

		num_of_cases[depth] = numbers[i];

		visit[i] = true;
		dfs(depth + 1);
		visit[i] = false;
	}
}

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &numbers[i]);
	}

	maxAns = -1;

	dfs(0);

	printf("%d\n", maxAns);

	return 0;
}