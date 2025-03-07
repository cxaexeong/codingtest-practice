#include <bits/stdc++.h>
using namespace std;

int solution(int storey) {
    int answer = 0;

    while (storey > 0) {
        int digit = storey % 10; // 현재 자리의 숫자
        int next_digit = (storey / 10) % 10; // 다음 자리의 숫자

        if (digit < 5) {
            answer += digit; // 그냥 내리기
        } else if (digit > 5) {
            answer += (10 - digit); // 올려서 조정
            storey += 10; // 다음 자리에서 반영
        } else { // digit == 5
            if (next_digit >= 5) {
                storey += 10; // 올리는 게 유리함
            }
            answer += 5;
        }

        storey /= 10; // 다음 자리 이동
    }

    return answer;
}