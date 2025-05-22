#include <stdio.h>

int main() {
    int a,b;
    scanf("%d %d", &a, &b);
    // a,b는 int지만 나눗셈에서 실수형 결과를 원하므로 형 변환
    printf("%.15lf\n", (double)a/b);
    return 0;
}