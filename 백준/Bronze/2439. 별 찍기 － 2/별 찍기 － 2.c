#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        // 공백 출력: n - i개
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        // 별 출력
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}