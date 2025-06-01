#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int busket[n];
    for (int i = 0; i < n; i++) busket[i] = 0;
    
    for (int cnt = 0; cnt < m; cnt++) {
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);
        for (int a = i-1; a < j; a++) {
            busket[a] = k;
        }
    } 
    for (int i = 0; i < n; i++) {
        printf("%d ", busket[i]);
    }
    return 0;
}