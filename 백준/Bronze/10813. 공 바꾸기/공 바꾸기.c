#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int busket[101];
    
    for (int i = 1; i <= n; i++) {
        busket[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int tmp = busket[a];
        busket[a] = busket[b];
        busket[b] = tmp;
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", busket[i]);
    }
    return 0;
}
