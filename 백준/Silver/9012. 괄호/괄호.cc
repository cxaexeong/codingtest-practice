#include <stdio.h>
int T;
int main() {
    scanf("%d", &T);
    
    for (int tc = 0; tc < T; tc++) {
        char str[50+5];
        int sp, length;
        bool flag;     // true = 올바르지 않은 괄호
        
        scanf("%s", str);
        sp = 0;
        
        for (length = 0; str[length]; length++); // 문자열 길이
        
        flag = false;
        // 스택배열 선언X, 스택포인터만 바꾸면서 최종적으로 0이 되냐, 음수냐만 판단
        
        for (int i = 0; i < length; i++) {
            int ch = str[i];
            if (ch == '(') sp++;    // 열린 괄호면 스택 증가 시킴
            else --sp;
            
            // 열린괄호면 +, 닫힌괄호면 -
            
            if (sp < 0) {
                flag = true;
                break;
            }
        }
        
        if (flag == true || sp != 0) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}