#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d\n", &a, &b);
    scanf("%d", &c);
    
    int total_min = b + c;
    a = (a + total_min / 60) % 24;
    b = total_min % 60;
    
    printf("%d %d", a, b);
    return 0;    
}