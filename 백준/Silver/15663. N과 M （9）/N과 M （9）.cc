#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX (8+8)

int N, M;
int num_of_cases[MAX];

int visit[MAX];
int numbers[MAX];
int possible[10000 + 500];

void printCases() {

	for (int i = 0; i < M; i++) {
		printf("%d ", num_of_cases[i]);
	}
	putchar('\n');
}

void DFS(int depth) {

	if (depth == M) {
		printCases();
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i] == possible[numbers[i]]) continue; // possible 만큼 썻으면 넘어감
		num_of_cases[depth] = numbers[i];

		visit[i]++;
		DFS(depth + 1);
		visit[i]--;
	}

}

int main() {

	scanf("%d %d", &N, &M);
	
	int count = 1; // numbers index 가리킴
	for (int i = 1; i <= N; i++) {
		// 값을 하나씩 받고
		int value;
		scanf("%d", &value);

		if (possible[value] == 0) numbers[count++] = value;

		// 받을 때마다 possible 배열을 하나씩 증가시켜줌
		possible[value]++;

	}

	N = count - 1;

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

	DFS(0);

	return 0;
}