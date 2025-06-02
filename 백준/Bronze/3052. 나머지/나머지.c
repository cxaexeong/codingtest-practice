#include <stdio.h>

int main() {
    int arr[10];
    int res[42] = {0};
    int n, cnt = 0;
    
    for (int i = 0; i < 10; i++) {
        scanf("%d", &n);
        arr[i] = n % 42;
        res[arr[i]] = 1; // 해당 나머지가 등장했음을 표시
    }
    
    for (int i = 0; i < 42; i++) {
        if (res[i] == 1) cnt++;
    }
    
    printf("%d\n", cnt);
    return 0;
}