#include <stdio.h>

#define MAX (50+5)
#define MAX_DEQUE (MAX * MAX * 2)
#define OFFSET (MAX_DEQUE / 2)

int N, M;
int position[MAX];

int deque[MAX_DEQUE * 2];
int front, back;

void input() {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) scanf("%d", &position[i]);

	// init
	front = back = OFFSET;

	for (int i = 1; i <= N; i++) deque[back++] = i;
}

int getLeftCount(int value) {

	int ret = 0;
	for (int i = front; i < back; i++) {
		if (deque[i] == value) return ret;
		
		ret++;

	}
	return -1; // error
}

int getRightCount(int value) {
	
	int ret = 0;
	for (int i = back - 1; i >= front; i--) {

		ret++; // 값을 찾은 후 3번 연산을 통해 앞으로 빼줘야 함. 그래서 먼저 ret++

		if (deque[i] == value) return ret;

	}
	return -1; // error
}

int main() {
	
	input();

	int ans = 0;

	for (int i = 0; i < M; i++) {
		
		if (deque[front] == position[i]) front++;
		else {
			int leftCount = getLeftCount(position[i]);
			int rightCount = getRightCount(position[i]);

			if (leftCount < rightCount) {
				for (int k = 0; k < leftCount; k++)
					deque[back++] = deque[front++];
				
				front++;

				ans += leftCount;
			}
			else {
				for (int k = 0; k < rightCount; k++) 
					deque[--front] = deque[--back]; // 뒤에 있는 원소를 뽑아서 앞으로 옮겨줌
				
				front++; // front 뽑고

				ans += rightCount;
			}
		}
	}

	printf("%d\n", ans);
}