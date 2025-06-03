#include <stdio.h>

int main() {
    int a,b,c;
    int count[10] = {0};
    scanf("%d %d %d", &a, &b, &c);
    
    int abc = a*b*c;
    
    while (abc > 0) {
        int digit = abc % 10;
        count[digit]++;
        abc /= 10;
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%d\n", count[i]);
    }
    return 0;    
}