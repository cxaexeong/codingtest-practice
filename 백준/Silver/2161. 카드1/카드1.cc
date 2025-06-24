#include <stdio.h>
#define MAX (1000+100)

int N;
int queue[MAX*2];
int rp, wp;

int main() {
    scanf("%d", &N);
    
    rp = wp = 0;
        
    for (int i = 1; i <= N; i++) queue[wp++] = i;
    
    for (int i = 0; i < N - 1; i++) {
        // 맨 앞 카드 출력 후 버리고
        printf("%d ", queue[rp++]);
        // 다음 카드는 큐에 푸시
        queue[wp++] = queue[rp++];
    }
    // 마지막 남은 카드도 출력해야 함 (카드가 1개만 남았기 때문에 rp로 출력해도 됨)
    printf("%d\n", queue[wp - 1]);
    return 0;
}