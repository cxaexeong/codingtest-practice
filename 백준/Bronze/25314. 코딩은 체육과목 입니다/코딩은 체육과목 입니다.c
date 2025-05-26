#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int c = n / 4;
    for (int i = 0; i < c; i++) {
        printf("long ");
    }
    printf("int\n");
    return 0;
}