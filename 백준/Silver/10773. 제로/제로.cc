#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    
    stack<int> s;
    int num;
    
    while (k--){
        cin >> num;
        
        if (num == 0){
            if (!s.empty()){
                s.pop();
            }
        } else {
            s.push(num);
        }
    }
    
    // 스택에 남아있는 숫자의 합 계산
    int sum = 0;
    while (!s.empty()){
        sum += s.top();
        s.pop();
    }
    
    cout << sum << '\n';
    return 0;
}