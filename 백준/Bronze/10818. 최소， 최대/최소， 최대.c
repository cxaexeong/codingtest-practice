#include <stdio.h>


int main() {

	int t;
	int a;
	scanf("%d", &t);

	int min = 1000000, max = -1000000;

	for (int i = 0; i < t; i++) {
		scanf("%d", &a);
		if (max < a) max = a;
		if (min > a) min = a;
	}

	printf("%d %d", min, max);
	


	return 0;
}