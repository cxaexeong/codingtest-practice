#include <stdio.h>
#define MAX (10000+500)
int N;
int queue[MAX];
int rp, wp;    // read pointer, write pointer

int strCompare(const char *a, const char *b) {
    while (*a && *a == *b) ++a, ++b;
    return *a - *b;
}

int main() {
    
    rp = wp = 0;
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        char command[100];
        
        scanf("%s", &command);
        
        if (strCompare(command, "push") == 0) {
            int value;
            scanf("%d", &value);
            queue[wp] = value;
            wp++;
        }
        else if (strCompare(command, "pop") == 0) {
            printf("%d\n", (wp == rp) ? -1 : queue[rp++]);
            //rp++;
        }
        else if (strCompare(command, "size") == 0) {
            printf("%d\n", wp - rp);
        }
        else if (strCompare(command, "empty") == 0) {
            printf("%d\n", wp == rp);
        }
        else if (strCompare(command, "front") == 0) {
            printf("%d\n", (wp == rp) ? -1 : queue[rp]);
        }
        else if (strCompare(command, "back") == 0) {
            printf("%d\n", (wp == rp) ? -1 : queue[wp-1]);
        }
    }
}