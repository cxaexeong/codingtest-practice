#include <stdio.h>

int main() {
    int arr[9];
    int mx = 0;
    int mx_idx = 0;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
        if (mx < arr[i]) {
            mx = arr[i];
            mx_idx = i;
        }
    }
    printf("%d\n", mx);
    printf("%d\n", mx_idx + 1);
    return 0;
}