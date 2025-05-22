#include <stdio.h>

int main() {
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);
    
    int b1 = b % 10;
    int b10 = (b/10) % 10;
    int b100 = b / 100;
    
    printf("%d\n", a*b1);
    printf("%d\n", a*b10);
    printf("%d\n", a*b100);
    printf("%d\n", a*b);
    
    return 0;
}