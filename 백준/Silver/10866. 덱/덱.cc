#include <stdio.h>
#define MAX (10000+100)
#define OFFSET (MAX / 2)

int N;
int deque[MAX*2];
int front, back;

int mystrcmp(const char *a, const char *b) {
    while (*a && *a == *b) a++, b++;
    return *a - *b;
}

void printDeque() {
    for (int i = front; i < back; i++) {
        printf("%d ", deque[i]);
    }
    putchar('\n');
}

int main() {
    
    front = back = OFFSET;    // 가운데부터 시작 (front는 -index가 될 수 있으므로)
    
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        char command[100];
        scanf("%s", command);
        
        if (mystrcmp(command, "push_front") == 0) {
            int value;
            scanf("%d", &value);
            deque[--front] = value; // 포인터를 감소 시킨 후 거기에 값을 대입
        }
        else if (mystrcmp(command, "push_back") == 0) {
            int value;
            scanf("%d", &value);
            deque[back++] = value;    // 포인터를 증가 시킨 후 거기에 값을 대입
        }
        else if (mystrcmp(command, "pop_front") == 0) 
            printf("%d\n",(back == front)? -1 : deque[front++]);
        else if (mystrcmp(command, "pop_back") == 0)
            printf("%d\n", (back == front)? -1 : deque[--back]);
        else if (mystrcmp(command, "size") == 0)
            printf("%d\n", back - front);
        else if (mystrcmp(command, "empty") == 0)
            printf("%d\n", (back == front)? 1 : 0);
        else if (mystrcmp(command, "front") == 0)
            printf("%d\n", (back == front? -1 : deque[front]));
        else if (mystrcmp(command, "back") == 0)
            printf("%d\n", (back == front)? -1 : deque[back-1]);
    }
    return 0;
}