#include <iostream>
#include <string>
#include <cmath> // abs() 사용
#include <map>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    
    // 각 문자열의 문자 빈도수 계산
    map<char,int> count_a, count_b;
    
    for (char c : a){
        count_a[c]++;
    }
    
    for (char c : b){
        count_b[c]++;
    }
    
    // 문자 차이 계산
    int diff = 0;
    for (char c = 'a'; c <= 'z'; c++){ //모든 소문자 알파벳에 대해
        diff += abs(count_a[c] - count_b[c]);
    }
    
    cout << diff << endl;
    return 0;
}