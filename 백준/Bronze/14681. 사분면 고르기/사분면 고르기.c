#include <stdio.h>

int main() {
    int x, y;
    scanf("%d\n", &x);
    scanf("%d\n", &y);
    
    if (x > 0 && y > 0) printf("1");
    else if (x > 0 && y < 0) printf("4");
    else if (x < 0 && y > 0) printf("2");
    else if (x < 0 && y < 0) printf("3");
    return 0;
}