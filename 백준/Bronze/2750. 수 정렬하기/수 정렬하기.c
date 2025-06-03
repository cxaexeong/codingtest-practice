#include <stdio.h>

int main() {
    int n, arr[1000];
    scanf("%d", &n);

    // 입력 받기
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 버블 정렬
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // 출력
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
