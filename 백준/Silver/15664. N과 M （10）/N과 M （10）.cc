#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX (8+8)

int N, M;
int num_of_cases[MAX];
int numbers[MAX];

int visit[MAX];
int possible[10000+500];

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

		if (visit[i] == possible[numbers[i]]) continue;

		num_of_cases[depth] = numbers[i];
		
		visit[i]++;
		dfs(depth + 1, i);
		visit[i]--;
	}

}

int main() {

	scanf("%d %d", &N, &M);

	int count = 1;
	for (int i = 1; i <= N; i++) {
		int value;
		scanf("%d", &value);

		if (possible[value] == 0) numbers[count++] = value;

		possible[value]++;
	}

	N = count - 1;

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