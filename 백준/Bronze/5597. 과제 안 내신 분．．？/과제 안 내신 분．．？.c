#include <stdio.h>

int main() {
    int n;
    int arr[31] = {0};  // 인덱스 1~30 사용

    // 28명 입력 받기
    for (int i = 0; i < 28; i++) {
        scanf("%d", &n);
        arr[n] = 1;  // 출석 표시
    }

    // 출석 안 한 번호 찾기
    for (int i = 1; i <= 30; i++) {
        if (arr[i] == 0)  // 출석 안 했으면
            printf("%d\n", i);  // 번호 출력
    }

    return 0;
}
