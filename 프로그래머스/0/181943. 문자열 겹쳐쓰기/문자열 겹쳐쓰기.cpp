#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    my_string.replace(s, overwrite_string.length(), overwrite_string);
    return my_string;
}

/*
string::replace(pos, len, str) 함수는 문자열 my_string에서 pos 위치부터 len 길이만큼의 문자열을 str로 바꿉니다.
*/