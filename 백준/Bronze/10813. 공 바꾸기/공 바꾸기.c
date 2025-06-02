#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int busket[100];
    for (int i = 1; i < n+1; i++) busket[i] = i;
    
    for (int cnt = 0; cnt < m; cnt++) {
        int i, j;
        scanf("%d %d", &i, &j);
        
        int tmp = busket[i];
        busket[i] = busket[j];
        busket[j] = tmp;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", busket[i]);
    }
    return 0;
}