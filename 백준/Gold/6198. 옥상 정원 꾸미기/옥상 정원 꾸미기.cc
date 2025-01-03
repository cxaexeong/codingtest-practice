#include <bits/stdc++.h>
using namespace std;

stack<int> st; // 스택 변수 이름 변경
int n;
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    long long h;
    while (n--) {
        cin >> h;
        while (!st.empty() && st.top() <= h) 
            st.pop();
        ans += st.size();
        st.push(h);  // 스택에 현재 높이 추가
    }
    cout << ans;
    return 0;    
}